#include <stdio.h>

#define ROWS 139
#define COLUMNS 139

char diagram[ROWS][COLUMNS];

int countAdjacencies(int part)
{
    int count = 0;

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            if (diagram[i][j] == '@')
            {
                int adjacentCount = 0;

                if (i > 0)
                {
                    if (j > 0)
                    {
                        if (diagram[i - 1][j - 1] == '@')
                        {
                            adjacentCount++;
                        }
                    }
                    if (diagram[i - 1][j] == '@')
                    {
                        adjacentCount++;
                    }
                    if (j < COLUMNS - 1)
                    {
                        if (diagram[i - 1][j + 1] == '@')
                        {
                            adjacentCount++;
                        }
                    }
                }

                if (j > 0)
                {
                    if (diagram[i][j - 1] == '@')
                    {
                        adjacentCount++;
                    }
                }
                // diagram[i][j]
                if (j < COLUMNS - 1)
                {
                    if (diagram[i][j + 1] == '@')
                    {
                        adjacentCount++;
                    }
                }

                if (i < ROWS - 1)
                {
                    if (j > 0)
                    {
                        if (diagram[i + 1][j - 1] == '@')
                        {
                            adjacentCount++;
                        }
                    }
                    if (diagram[i + 1][j] == '@')
                    {
                        adjacentCount++;
                    }
                    if (j < COLUMNS - 1)
                    {
                        if (diagram[i + 1][j + 1] == '@')
                        {
                            adjacentCount++;
                        }
                    }
                }

                if (adjacentCount < 4)
                {
                    count++;

                    if (part == 2)
                    {
                        diagram[i][j] = '.';
                    }
                }
            }
        }
    }

    return count;
};

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    int part1Count = 0;
    int part2Count = 0;

    // populate diagram
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            fscanf(fptr, "%1c", &diagram[i][j]);
            // printf("%c", diagram[i][j]);
        }
        fscanf(fptr, "\n");
        // printf("\n");
    }

    // part 1
    part1Count += countAdjacencies(1);

    // part 2
    int loopCount = 1;

    while (loopCount != 0)
    {
        loopCount = countAdjacencies(2);
        part2Count += loopCount;
    }
    

    printf("part 1: %d\n", part1Count);
    printf("part 2: %d\n", part2Count);

    return 0;
}
