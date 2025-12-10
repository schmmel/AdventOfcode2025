#include <stdio.h>

#define INGREDIENTCOUNT 1000
#define RANGECOUNT 179

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    long long ingredients[INGREDIENTCOUNT];
    long long rangeStarts[RANGECOUNT];
    long long rangeEnds[RANGECOUNT];

    long long part1Count = 0;
    long long part2Count = 0;

    int i = 0;
    char line[256];

    while (fgets(line, sizeof(line), fptr))
    {
        if (line[0] == '\n' || line[0] == '\r')
        {
            break;
        }

        if (sscanf(line, "%lld-%lld", &rangeStarts[i], &rangeEnds[i]) == 2)
        {
            // printf("%lld-%lld\n", rangeStarts[i], rangeEnds[i]);

            i++;
        }
    }

    // printf("\n");

    i = 0;
    while (fscanf(fptr, "%lld", &ingredients[i]) == 1)
    {
        // printf("%lld %d\n", ingredients[i], i);
        i++;
    }

    for (int i = 0; i < INGREDIENTCOUNT; i++)
    {
        // printf("%lld\n", ingredients[i]);

        for (int j = 0; j < RANGECOUNT; j++)
        {
            // printf("%lld %lld %lld\n", ingredients[i], rangeStarts[j], rangeEnds[j]);

            if (ingredients[i] >= rangeStarts[j] &&
                ingredients[i] <= rangeEnds[j])
            {
                part1Count++;
                break;
            }
        }
    }

    int freshRangeCount = 0;
    long long freshRanges[100000][2];
    for (int i = 0; i < RANGECOUNT; i++)
    {
        // printf("%lld %lld\n", rangeStarts[i], rangeEnds[i]);

        if (i == 0)
        {
            freshRanges[0][0] = rangeStarts[i];
            freshRanges[0][1] = rangeEnds[i];
            continue;
        }

        int rangeFound = 0;

        for (int j = 0; j <= freshRangeCount; j++)
        {

            // printf("%lld-%lld %lld-%lld ", rangeStarts[i], rangeEnds[i], freshRanges[j][0], freshRanges[j][1]);

            if (rangeStarts[i] <= freshRanges[j][0] &&
                rangeEnds[i] >= freshRanges[j][1])
            {
                freshRanges[j][0] = rangeStarts[i];
                freshRanges[j][1] = rangeEnds[i];
                rangeFound = 1;
                // printf("%lld-%lld\n", freshRanges[j][0], freshRanges[j][1]);
                continue;
            }

            if (rangeStarts[i] >= freshRanges[j][0] &&
                rangeEnds[i] <= freshRanges[j][1])
            {
                rangeFound = 1;
                // printf("%lld-%lld\n", freshRanges[j][0], freshRanges[j][1]);
                continue;
            }

            if (rangeStarts[i] < freshRanges[j][0] && rangeEnds[i] >= freshRanges[j][0] - 1)
            {
                freshRanges[j][0] = rangeStarts[i];
                rangeFound = 1;
                // printf("%lld-%lld\n", freshRanges[j][0], freshRanges[j][1]);
                continue;
            }

            if (rangeEnds[i] > freshRanges[j][1] && rangeStarts[i] <= freshRanges[j][1] + 1)
            {
                freshRanges[j][1] = rangeEnds[i];
                rangeFound = 1;
                // printf("%lld-%lld\n", freshRanges[j][0], freshRanges[j][1]);
                continue;
            }

            // printf("\n");
        }

        if (!rangeFound)
        {
            freshRangeCount++;
            freshRanges[freshRangeCount][0] = rangeStarts[i];
            freshRanges[freshRangeCount][1] = rangeEnds[i];
        }
    }

    for (int i = 0; i <= freshRangeCount; i++)
    {
        if (freshRanges[i][0] == 0 && freshRanges[i][1] == 0)
        {
            continue;
        }

        long long freshStart = freshRanges[i][0];
        long long freshEnd = freshRanges[i][1];

        // printf("\n%lld-%lld\n", freshRanges[i][0], freshRanges[i][1]);

        for (int j = 0; j <= freshRangeCount; j++)
        {
            if (i == j ||
                (freshRanges[j][0] == 0 && freshRanges[j][1] == 0))
            {
                continue;
            }

            // printf("%lld-%lld %lld-%lld\n", freshStart, freshEnd, freshRanges[j][0], freshRanges[j][1]);

            if (freshStart <= freshRanges[j][0] &&
                freshEnd >= freshRanges[j][0])
            {
                freshRanges[i][1] = freshRanges[j][1];
                freshRanges[j][0] = 0;
                freshRanges[j][1] = 0;
            }

            if (freshEnd >= freshRanges[j][1] &&
                freshStart <= freshRanges[j][1])
            {
                freshRanges[i][0] = freshRanges[j][0];
                freshRanges[j][0] = 0;
                freshRanges[j][1] = 0;
            }
        }
    }

    printf("\n");

    for (int i = 0; i <= freshRangeCount; i++)
    {
        if (freshRanges[i][0] == 0 && freshRanges[i][1] == 0)
        {
            continue;
        }

        long long result = freshRanges[i][1] - freshRanges[i][0] + 1;
        // printf("%lld-%lld %lld\n", freshRanges[i][0], freshRanges[i][1], result);

        part2Count += result;
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}