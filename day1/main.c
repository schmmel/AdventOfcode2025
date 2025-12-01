#include <stdio.h>

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    char direction;
    int rotations;

    // high start so we never have to deal with negative numbers
    int dial = 100050;
    int part1Count = 0;
    int part2Count = 0;

    while (fscanf(fptr, "%c%d\n", &direction, &rotations) == 2)
    {
        if (direction == 'R')
        {
            // printf("%d %c %d %d\n", dial, direction, rotations, dial + rotations);
            // printf("%d\n", ((dial + rotations) / 100) - (dial / 100));

            // dont count double if we start from 0
            if (dial % 100 == 0 && (dial % 100) == ((dial + rotations) % 100))
            {
                // printf("-1 \n");
                part2Count--;
            }

            part2Count += ((dial + rotations) / 100) - (dial / 100);

            dial += rotations;
        }
        else
        {
            // printf("%d %c %d %d\n", dial, direction, rotations, dial - rotations);
            // printf("%d\n", (dial / 100) - (dial - rotations) / 100);

            // count if we end at 0
            if ((dial - rotations) % 100 == 0)
            {
                // printf("+1 \n");
                part2Count++;
            }

            // dont count double if we start from 0
            if (dial % 100 == 0)
            {
                // printf("-1 \n");
                part2Count--;
            }

            part2Count += (dial / 100) - ((dial - rotations) / 100);

            dial -= rotations;
        }

        if (dial % 100 == 0)
        {
            part1Count++;
        }
    }

    printf("part 1: %d\n", part1Count);
    printf("part 2: %d\n", part2Count);

    return 0;
}