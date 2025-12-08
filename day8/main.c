#include <stdio.h>
#include <math.h>

#define BOXCOUNT 200

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    long long part1Count = 0;
    long long part2Count = 0;

    long long junctionBoxes[BOXCOUNT][3];
    // long long distances[BOXCOUNT][BOXCOUNT];

    long long distances[BOXCOUNT * BOXCOUNT];
    long long distanceBoxes[BOXCOUNT * BOXCOUNT][2];

    int i = 0;
    while (fscanf(fptr, "%lld,%lld,%lld\n", &junctionBoxes[i][0], &junctionBoxes[i][1], &junctionBoxes[i][2]) == 3 && i < BOXCOUNT)
    {
        printf("%lld %lld %lld\n", junctionBoxes[i][0], junctionBoxes[i][1], junctionBoxes[i][2]);
        i++;
    }

    long long k = 0;
    for (long long i = 0; i < BOXCOUNT; i++)
    {
        for (long long j = 0; j < BOXCOUNT; j++)
        {
            if (i == j)
            {
                distances[k] = 0;
            }
            else
            {
                distances[k] = sqrt(pow(junctionBoxes[i][0] - junctionBoxes[j][0], 2) + pow(junctionBoxes[i][1] - junctionBoxes[j][1], 2) + pow(junctionBoxes[i][2] - junctionBoxes[j][2], 2));
            }

            distanceBoxes[k][0] = i;
            distanceBoxes[k][1] = j;

            // printf("%lld \n", distances[k]);

            k++;

            // printf("%lld,%lld,%lld %lld,%lld,%lld ", junctionBoxes[i][0], junctionBoxes[i][1], junctionBoxes[i][2], junctionBoxes[j][0], junctionBoxes[j][1], junctionBoxes[j][2]);

            // printf("%lld\n", distance);
        }
        // printf("\n");
    }
    // printf("\n");


    for (long long i = 1; i < BOXCOUNT * BOXCOUNT; i++)
    {
        long long coord1 = distanceBoxes[i][0];
        long long coord2 = distanceBoxes[i][1];

        long long key = distances[i];
        long long j = i - 1;

        while (j >= 0 && key < distances[j])
        {
            distanceBoxes[j + 1][0] = distanceBoxes[j][0];
            distanceBoxes[j + 1][1] = distanceBoxes[j][1];

            distances[j + 1] = distances[j];

            --j;
        }

        distanceBoxes[j + 1][0] = coord1;
        distanceBoxes[j + 1][1] = coord2;

        distances[j + 1] = key;
    }

    for (int i = 0; i < BOXCOUNT * BOXCOUNT; i++)
    {
        printf("%lld %lld %lld\n", distances[i], distanceBoxes[i][0], distanceBoxes[i][1]);
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}