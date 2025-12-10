#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TILECOUNT 496

int cornerInsideRectilinearPolygon(long long cornerX, long long cornerY,
                                   long long polyX[], long long polyY[], int n)
{
    int inside = 0;
    for (int i = 0, j = n - 1; i < n; j = i++)
    {
        long long x1 = polyX[j], y1 = polyY[j];
        long long x2 = polyX[i], y2 = polyY[i];

        if ((x1 == x2 && cornerX == x1 && cornerY >= (y1 < y2 ? y1 : y2) && cornerY <= (y1 > y2 ? y1 : y2)) ||
            (y1 == y2 && cornerY == y1 && cornerX >= (x1 < x2 ? x1 : x2) && cornerX <= (x1 > x2 ? x1 : x2)))
            return 1;

        if ((y1 > cornerY) != (y2 > cornerY))
        {
            long long xIntersect = x1 + (cornerY - y1) * (x2 - x1) / (y2 - y1);
            if (cornerX < xIntersect)
            {
                inside = !inside;
            }
        }
    }
    return inside;
}

int overlap(long long a1, long long a2, long long b1, long long b2)
{
    if (a1 > a2)
    {
        long long t = a1;
        a1 = a2;
        a2 = t;
    }
    if (b1 > b2)
    {
        long long t = b1;
        b1 = b2;
        b2 = t;
    }
    return (a1 < b2) && (b1 < a2);
}

int rectangleFullyInsidePolygon(long long x1, long long y1, long long x2, long long y2,
                                long long polyX[], long long polyY[], int n)
{
    // 4 corners of rectangle
    long long rectXMin = x1 < x2 ? x1 : x2;
    long long rectXMax = x1 > x2 ? x1 : x2;
    long long rectYMin = y1 < y2 ? y1 : y2;
    long long rectYMax = y1 > y2 ? y1 : y2;

    if (!cornerInsideRectilinearPolygon(rectXMin, rectYMin, polyX, polyY, n))
        return 0;
    if (!cornerInsideRectilinearPolygon(rectXMin, rectYMax, polyX, polyY, n))
        return 0;
    if (!cornerInsideRectilinearPolygon(rectXMax, rectYMin, polyX, polyY, n))
        return 0;
    if (!cornerInsideRectilinearPolygon(rectXMax, rectYMax, polyX, polyY, n))
        return 0;

    for (int i = 0, j = n - 1; i < n; j = i++)
    {
        long long polyX1 = polyX[j], polyY1 = polyY[j];
        long long polyX2 = polyX[i], polyY2 = polyY[i];

        if (polyX1 == polyX2) // vertical edge
        {
            if (polyX1 > rectXMin && polyX1 < rectXMax && overlap(rectYMin, rectYMax, polyY1, polyY2))
                return 0;
        }
        else if (polyY1 == polyY2) // horizontal edge
        {
            if (polyY1 > rectYMin && polyY1 < rectYMax && overlap(rectXMin, rectXMax, polyX1, polyX2))
                return 0;
        }
    }

    return 1;
}

int compareRow(const void *a, const void *b)
{
    const double *ra = a;
    const double *rb = b;

    if (ra[0] > rb[0])
        return -1;
    if (ra[0] < rb[0])
        return 1;
    return 0;
}

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    long long part1Count = 0;
    long long part2Count = 0;

    long long redTiles[TILECOUNT][2];
    long long (*rectangles)[3] = malloc(TILECOUNT * TILECOUNT * sizeof *rectangles);
    long long (*part2Rectangles)[3] = malloc(TILECOUNT * TILECOUNT * sizeof *part2Rectangles);

    for (int i = 0; i < TILECOUNT; i++)
    {
        fscanf(fptr, "%lld,%lld\n", &redTiles[i][0], &redTiles[i][1]);
        // printf("%lld,%lld\n", redTiles[i][0], redTiles[i][1]);
    }

    // part 1
    int k = 0;
    for (int i = 0; i < TILECOUNT; i++)
    {
        for (int j = 0; j < TILECOUNT; j++)
        {
            // printf("%lld,%lld %lld,%lld ", redTiles[i][0], redTiles[i][1], redTiles[j][0], redTiles[j][1]);

            long long deltaX = abs(redTiles[i][0] - redTiles[j][0]);
            long long deltaY = abs(redTiles[i][1] - redTiles[j][1]);

            long long rectangleSize = (deltaX + 1) * (deltaY + 1);
            // printf("%lld %lld %lld\n", deltaX, deltaY, rectangleSize);

            rectangles[k][0] = rectangleSize;
            rectangles[k][1] = i;
            rectangles[k][2] = j;

            k++;
        }
    }

    qsort(rectangles, TILECOUNT * TILECOUNT, sizeof(rectangles[0]), compareRow);

    // for (int i = 0; i < TILECOUNT; i++)
    // {
    //     printf("%lld %lld %lld\n", rectangles[i][0], rectangles[i][1], rectangles[i][2]);
    // }

    part1Count = rectangles[0][0];

    // part 2
    long long polyX[TILECOUNT];
    long long polyY[TILECOUNT];

    for (int i = 0; i < TILECOUNT; i++)
    {
        polyX[i] = redTiles[i][0];
        polyY[i] = redTiles[i][1];
        printf("%lld,%lld\n", polyX[i], polyY[i]);
    }

    k = 0;
    for (int i = 0; i < TILECOUNT; i++)
    {
        for (int j = 0; j < TILECOUNT; j++)
        {
            // printf("%lld,%lld %lld,%lld\n", redTiles[i][0], redTiles[i][1], redTiles[j][0], redTiles[j][1]);

            if (rectangleFullyInsidePolygon(redTiles[i][0], redTiles[i][1],
                                            redTiles[j][0], redTiles[j][1],
                                            polyX, polyY, TILECOUNT))
            {
                long long deltaX = abs(redTiles[i][0] - redTiles[j][0]);
                long long deltaY = abs(redTiles[i][1] - redTiles[j][1]);

                long long rectangleSize = (deltaX + 1) * (deltaY + 1);
                // printf("%lld %lld %lld\n", deltaX, deltaY, rectangleSize);

                part2Rectangles[k][0] = rectangleSize;
                part2Rectangles[k][1] = i;
                part2Rectangles[k][2] = j;

                k++;
            }
        }
    }

    qsort(part2Rectangles, TILECOUNT * TILECOUNT, sizeof(part2Rectangles[0]), compareRow);

    for (int i = 0; i < 10; i++)
    {
        printf("%lld %lld %lld\n", part2Rectangles[i][0], part2Rectangles[i][1], part2Rectangles[i][2]);
    }

    part2Count = part2Rectangles[0][0];

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}