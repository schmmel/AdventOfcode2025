#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BOXCOUNT 1000

int compareRow(const void *a, const void *b)
{
    const double *ra = a;
    const double *rb = b;

    if (ra[0] < rb[0])
        return -1;
    if (ra[0] > rb[0])
        return 1;
    return 0;
}

int compare(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    long long part1Count = 0;
    long long part2Count = 0;

    long long junctionBoxes[BOXCOUNT][3];

    double (*distances)[3] = malloc(BOXCOUNT * BOXCOUNT * sizeof *distances);

    int (*circuits)[BOXCOUNT] = malloc(100000 * sizeof *circuits);
    int *circuitSize = malloc(100000 * sizeof *circuitSize);

    int circuitCount = 0;

    for (int i = 0; i < BOXCOUNT; i++)
    {
        fscanf(fptr, "%lld,%lld,%lld\n", &junctionBoxes[i][0], &junctionBoxes[i][1], &junctionBoxes[i][2]);

        // printf("%lld %lld %lld\n", junctionBoxes[i][0], junctionBoxes[i][1], junctionBoxes[i][2]);
    }

    int k = 0;
    for (int i = 0; i < BOXCOUNT; i++)
    {
        for (int j = 0; j < BOXCOUNT; j++)
        {
            if (i == j)
            {
                distances[k][0] = 0;
            }
            else
            {
                long long d1 = junctionBoxes[i][0] - junctionBoxes[j][0];
                long long d2 = junctionBoxes[i][1] - junctionBoxes[j][1];
                long long d3 = junctionBoxes[i][2] - junctionBoxes[j][2];

                distances[k][0] = sqrt(pow(d1, 2) + pow(d2, 2) + pow(d3, 2));

                // printf("%d %d\n", i, j);
                // printf("%lld %lld %lld %lld %lld %lld\n", junctionBoxes[i][0], junctionBoxes[i][1], junctionBoxes[i][2], junctionBoxes[j][0], junctionBoxes[j][1], junctionBoxes[j][2]);
                // printf("%lld %lld %lld %f\n\n", d1, d2, d3, distances[k][0]);
            }

            distances[k][1] = i;
            distances[k][2] = j;

            // printf("%lld \n", distances[k]);

            k++;

            // printf("%lld,%lld,%lld %lld,%lld,%lld ", junctionBoxes[i][0], junctionBoxes[i][1], junctionBoxes[i][2], junctionBoxes[j][0], junctionBoxes[j][1], junctionBoxes[j][2]);

            // printf("%lld\n", distance);
        }
        // printf("\n");
    }
    // printf("\n");

    qsort(distances, BOXCOUNT * BOXCOUNT, sizeof(distances[0]), compareRow);

    // for (int i = BOXCOUNT; i < BOXCOUNT * BOXCOUNT; i += 2)
    // {
    //     printf("%d %f %d %d %d %d\n", i, distances[i][0], (int)distances[i][1], (int)distances[i][2], junctionBoxes[(int)distances[i][1]][0], junctionBoxes[(int)distances[i][2]][0]);
    // }

    for (int i = BOXCOUNT; i < BOXCOUNT + BOXCOUNT * 2; i += 2)
    {
        int box1 = (int)distances[i][1];
        int box2 = (int)distances[i][2];

        int circuit1 = -1;
        int circuit2 = -1;

        for (int j = 0; j < circuitCount; j++)
        {
            for (int k = 0; k < circuitSize[j]; k++)
            {
                if (circuits[j][k] == box1)
                {
                    circuit1 = j;
                }
                if (circuits[j][k] == box2)
                {
                    circuit2 = j;
                }
            }
        }

        // create new circuit if neither exist
        if (circuit1 == -1 && circuit2 == -1)
        {
            circuits[circuitCount][0] = box1;
            circuits[circuitCount][1] = box2;
            circuitSize[circuitCount] = 2;
            circuitCount++;
        }
        else if (circuit1 != -1 && circuit2 == -1)
        {
            circuits[circuit1][circuitSize[circuit1]++] = box2;
        }
        else if (circuit1 == -1 && circuit2 != -1)
        {
            circuits[circuit2][circuitSize[circuit2]++] = box1;
        }
        else if (circuit1 != circuit2)
        {
            for (int k = 0; k < circuitSize[circuit2]; k++)
            {
                circuits[circuit1][circuitSize[circuit1]++] = circuits[circuit2][k];
            }

            circuitSize[circuit2] = 0;
        }

        // printf("%d %f %d %d\n", i, distances[i][0], box1, box2);
    }

    // // printf("\n");

    // // for (int i = 0; i < circuitCount; i++)
    // // {
    // //     printf("circuit %d (size %d): ", i, circuitSize[i]);
    // //     for (int j = 0; j < circuitSize[i]; j++)
    // //         printf("%d ", circuits[i][j]);
    // //     printf("\n");
    // // }

    qsort(circuitSize, circuitCount, sizeof(circuitSize[0]), compare);

    // // for (int i = 0; i < circuitCount; i++)
    // // {
    // //     printf("%d\n", circuitSize[i]);
    // // }

    part1Count = circuitSize[0] * circuitSize[1] * circuitSize[2];

    int (*part2Circuits)[BOXCOUNT] = malloc(100000 * sizeof *part2Circuits);
    int *part2CircuitSize = malloc(100000 * sizeof *part2CircuitSize);

    int part2CircuitCount = 0;
    int nonEmptyCircuitCount = 0;

    int i = BOXCOUNT;
    // i = BOXCOUNT;

    int box1 = 0;
    int box2 = 0;

    for (int i = 0; i < BOXCOUNT; i++)
    {
        part2Circuits[i][0] = i;
        part2CircuitSize[i] = 1;
        part2CircuitCount++;
        nonEmptyCircuitCount++;
    }

    while (nonEmptyCircuitCount != 1 || i < BOXCOUNT + 5)
    {
        box1 = (int)distances[i][1];
        box2 = (int)distances[i][2];

        int circuit1 = -1;
        int circuit2 = -1;

        for (int j = 0; j < part2CircuitCount; j++)
        {
            for (int k = 0; k < part2CircuitSize[j]; k++)
            {
                if (part2Circuits[j][k] == box1)
                {
                    circuit1 = j;
                }
                if (part2Circuits[j][k] == box2)
                {
                    circuit2 = j;
                }
            }
        }

        // create new circuit if neither exist
        if (circuit1 == -1 && circuit2 == -1)
        {
            part2Circuits[part2CircuitCount][0] = box1;
            part2Circuits[part2CircuitCount][1] = box2;
            part2CircuitSize[part2CircuitCount] = 2;
            part2CircuitCount++;
            nonEmptyCircuitCount++;
        }
        else if (circuit1 != -1 && circuit2 == -1)
        {
            part2Circuits[circuit1][part2CircuitSize[circuit1]++] = box2;
        }
        else if (circuit1 == -1 && circuit2 != -1)
        {
            part2Circuits[circuit2][part2CircuitSize[circuit2]++] = box1;
        }
        else if (circuit1 != circuit2)
        {
            for (int k = 0; k < part2CircuitSize[circuit2]; k++)
            {
                part2Circuits[circuit1][part2CircuitSize[circuit1]++] = part2Circuits[circuit2][k];
            }

            part2CircuitSize[circuit2] = 0;
            nonEmptyCircuitCount--;
        }
        i += 1;
    }

    // printf("%d\n", i);

    // for (int i = 0; i < part2CircuitCount; i++)
    // {
    //     printf("circuit %d (size %d): ", i, part2CircuitSize[i]);
    //     for (int j = 0; j < part2CircuitSize[i]; j++)
    //         printf("%d ", part2Circuits[i][j]);
    //     printf("\n");
    // }

    // printf("%d %d\n", junctionBoxes[(int)distances[i][1]][0], junctionBoxes[(int)distances[i][2]][0]);

    // for (int i = 0; i < part2CircuitCount; i++)
    // {
    //     // if (part2CircuitSize[i] == 0)
    //     //     continue;

    //     // int box1 = circuits[i][circuitSize[i] - 2];
    //     // int box2 = circuits[i][circuitSize[i] - 1];
    //     printf("%d %d\n", junctionBoxes[box1][0], junctionBoxes[box2][0]);

    //     part2Count = junctionBoxes[(int)distances[i][1]][0] * junctionBoxes[(int)distances[i][2]][0];

    //     break;
    // }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld * %lld\n", junctionBoxes[(int)distances[i][1]][0], junctionBoxes[(int)distances[i][2]][0]);

    return 0;
}