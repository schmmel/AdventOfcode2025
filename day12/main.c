#include <stdio.h>
#include <stdlib.h>

#define SHAPECOUNT 6
#define SHAPESIZE 3
#define REGIONCOUNT 3

typedef struct
{
    int cells[SHAPESIZE][SHAPESIZE];
} Shape;

Shape shapes[6];

typedef struct
{
    int width;
    int height;
    int **grid;
} Bin;

Bin createBin(int width, int height)
{
    Bin b;
    b.width = width;
    b.height = height;

    b.grid = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++)
    {
        b.grid[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++)
        {
            b.grid[i][j] = 0;
        }
    }

    return b;
}

void freeBin(Bin *b)
{
    for (int i = 0; i < b->height; i++)
    {
        free(b->grid[i]);
    }
    free(b->grid);
}

void rotate90(Shape *s, Shape *out)
{
    for (int i = 0; i < SHAPESIZE; i++)
    {
        for (int j = 0; j < SHAPESIZE; j++)
        {
            out->cells[j][SHAPESIZE - 1 - i] = s->cells[i][j];
        }
    }
}

void flipHorizontal(Shape *s, Shape *out)
{
    for (int i = 0; i < SHAPESIZE; i++)
    {
        for (int j = 0; j < SHAPESIZE; j++)
        {
            out->cells[i][SHAPESIZE - 1 - j] = s->cells[i][j];
        }
    }
}

void flipVertical(Shape *s, Shape *out)
{
    for (int i = 0; i < SHAPESIZE; i++)
    {
        for (int j = 0; j < SHAPESIZE; j++)
        {
            out->cells[SHAPESIZE - 1 - i][j] = s->cells[i][j];
        }
    }
}

int canPlace(Bin *bin, Shape *shape, int x, int y)
{
    for (int i = 0; i < SHAPESIZE; i++)
    {
        for (int j = 0; j < SHAPESIZE; j++)
        {
            if (shape->cells[i][j])
            {
                int bx = x + j;
                int by = y + i;
                if (bx >= bin->width || by >= bin->height)
                {
                    return 0;
                }
                if (bin->grid[by][bx])
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

void placeShape(Bin *bin, Shape *shape, int x, int y)
{
    for (int i = 0; i < SHAPESIZE; i++)
    {
        for (int j = 0; j < SHAPESIZE; j++)
        {
            if (shape->cells[i][j])
            {
                bin->grid[y + i][x + j] = 1;
            }
        }
    }
}

int packShape(Bin *bin, Shape *shape)
{
    for (int y = 0; y <= bin->height - SHAPESIZE; y++)
    {
        for (int x = 0; x <= bin->width - SHAPESIZE; x++)
        {
            if (canPlace(bin, shape, x, y))
            {
                placeShape(bin, shape, x, y);
                return 1;
            }
        }
    }

    return 0;
}

int equalShape(Shape *a, Shape *b)
{
    for (int i = 0; i < SHAPESIZE; i++)
    {
        for (int j = 0; j < SHAPESIZE; j++)
        {
            if (a->cells[i][j] != b->cells[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

int generateVariants(Shape *original, Shape variants[12])
{
    Shape temp, candidate;
    int count = 0;

    Shape flips[3] = {*original};

    flipHorizontal(original, &flips[1]);
    flipVertical(original, &flips[2]);

    for (int f = 0; f < 3; f++)
    {
        temp = flips[f];
        for (int r = 0; r < 4; r++)
        {
            if (r > 0)
            {
                rotate90(&temp, &candidate);
            }
            else
            {
                candidate = temp;
            }

            int duplicate = 0;
            for (int k = 0; k < count; k++)
            {
                if (equalShape(&candidate, &variants[k]))
                {
                    duplicate = 1;
                    break;
                }
            }
            if (!duplicate)
            {
                variants[count++] = candidate;
            }

            temp = candidate;
        }
    }

    return count;
}

Shape allVariants[SHAPECOUNT][12];
int variantCount[SHAPECOUNT];

void generateAllVariants()
{
    for (int i = 0; i < SHAPECOUNT; i++)
    {
        variantCount[i] = generateVariants(&shapes[i], allVariants[i]);
    }
}

int packShapes(int binWidth, int binHeight, int copies[SHAPECOUNT], Bin outputBins[100])
{
    int binCount = 1;
    outputBins[0] = createBin(binWidth, binHeight);

    for (int i = 0; i < SHAPECOUNT; i++)
    {
        for (int j = 0; j < copies[i]; j++)
        {
            int placed = 0;

            for (int k = 0; k < variantCount[i]; k++)
            {
                if (packShape(&outputBins[binCount - 1], &allVariants[i][k]))
                {
                    placed = 1;
                    break;
                }
            }

            if (!placed)
            {
                outputBins[binCount] = createBin(binWidth, binWidth);
                binCount++;
                packShape(&outputBins[binCount - 1], &allVariants[i][0]);
            }
        }
    }

    return binCount;
}

int main()
{
    FILE *fptr = fopen("exampleinput.txt", "r");

    long long part1Count = 0;
    long long part2Count = 0;

    char buffer[640];

    // int shapes[SHAPECOUNT][SHAPESIZE][SHAPESIZE];
    int regions[REGIONCOUNT][2];
    int regionShapes[REGIONCOUNT][SHAPECOUNT];

    for (int i = 0; i < SHAPECOUNT; i++)
    {
        fgets(buffer, sizeof(buffer), fptr);

        int shapeIndex = 0;
        for (int j = 0; j < SHAPESIZE; j++)
        {
            fgets(buffer, sizeof(buffer), fptr);

            for (int k = 0; k < SHAPESIZE; k++)
            {
                if (buffer[k] == '#')
                {
                    shapes[i].cells[j][k] = 1;
                }
                else
                {
                    shapes[i].cells[j][k] = 0;
                }
            }
        }

        fgets(buffer, sizeof(buffer), fptr);
    }

    for (int i = 0; i < SHAPECOUNT; i++)
    {
        for (int j = 0; j < SHAPESIZE; j++)
        {
            printf("%d%d%d\n", shapes[i].cells[j][0], shapes[i].cells[j][1], shapes[i].cells[j][2]);
        }

        printf("\n");
    }

    for (int i = 0; i < REGIONCOUNT; i++)
    {
        // fgets(buffer, sizeof(buffer), fptr);

        fscanf(fptr, "%dx%d: %d %d %d %d %d %d", &regions[i][0], &regions[i][1], &regionShapes[i][0], &regionShapes[i][1], &regionShapes[i][2], &regionShapes[i][3], &regionShapes[i][4], &regionShapes[i][5]);

        printf("%dx%d: %d %d %d %d %d %d\n", regions[i][0], regions[i][1], regionShapes[i][0], regionShapes[i][1], regionShapes[i][2], regionShapes[i][3], regionShapes[i][4], regionShapes[i][5]);
    }

    generateAllVariants();

    Bin bins[100];

    for (int i = 0; i < REGIONCOUNT; i++)
    {
        int usedBins = packShapes(regions[i][0], regions[i][1], regionShapes[i], bins);
        printf("bins used: %d\n", usedBins);

        for (int i = 0; i < usedBins; i++)
        {
            freeBin(&bins[i]);
        }
        
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}