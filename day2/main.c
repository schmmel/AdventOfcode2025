#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int countOccurences(char *id, char *idPart)
{
    int idLength = strlen(id);
    int count = 0;

    char reading[64] = "";

    for (int i = 0; i < idLength; i++)
    {
        char tmp[2] = {id[i], '\0'};
        strcat(reading, tmp);
        // printf("%s %s %s\n", reading, tmp, idPart);

        if (strcmp(reading, idPart) == 0)
        {
            count++;
            memset(reading, 0, 64);
        }
    }

    return count;
}

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    long long rangeStart;
    long long rangeEnd;

    long long part1 = 0;
    long long part2 = 0;

    while (fscanf(fptr, "%lld-%lld,", &rangeStart, &rangeEnd) == 2)
    {
        // printf("%lld-%lld\n", rangeStart, rangeEnd);

        for (long long i = rangeStart; i <= rangeEnd; i++)
        {
            char id[64];
            snprintf(id, 64, "%lld", i);

            // part 1
            if (strlen(id) % 2 == 0)
            {
                char firstHalf[64], secondHalf[64];
                strncpy(firstHalf, id, strlen(id) / 2);
                strncpy(secondHalf, id + strlen(id) / 2, strlen(id));

                // printf("%lld %s %s %s %d\n", i, id, firstHalf, secondHalf, strcmp(firstHalf, secondHalf));

                if (strcmp(firstHalf, secondHalf) == 0)
                {
                    // printf("%lld %s %s %d\n", i, firstHalf, secondHalf, strcmp(firstHalf, secondHalf));
                    part1 += i;
                }

                // printf("%s %s\n", firstHalf, secondHalf);

                // char firstHalf[] = i;
                // printf("%s", firstHalf);

                memset(firstHalf, 0, 64);
                memset(secondHalf, 0, 64);
            }

            // part 2
            char idPart1[64], idPart2[64], idPart3[64], idPart4[64], idPart5[64];
            strncpy(idPart1, id, 1); // first char
            strncpy(idPart2, id, 2); // first 2 chars
            strncpy(idPart3, id, 3); // so on
            strncpy(idPart4, id, 4);
            strncpy(idPart5, id, 5);

            // printf("%s %s %s %s %s %lld\n", idPart1, idPart2, idPart3, idPart4, idPart5, i);

            switch (strlen(id))
            {
            case 2:
                // printf("------------\n");
                if (countOccurences(id, idPart1) == 2)
                {
                    part2 += i;
                }
                // printf("$$$ %s %s %d\n", id, idPart1, countOccurences(id, idPart1));
                break;
            case 3:
                if (countOccurences(id, idPart1) == 3)
                {
                    part2 += i;
                }
                break;
            case 4:
                if (countOccurences(id, idPart1) == 4 ||
                    countOccurences(id, idPart2) == 2)
                {
                    part2 += i;
                }
                break;
            case 5:
                if (countOccurences(id, idPart1) == 5)
                {
                    part2 += i;
                }
                break;
            case 6:
                if (countOccurences(id, idPart1) == 6 ||
                    countOccurences(id, idPart2) == 3 ||
                    countOccurences(id, idPart3) == 2)
                {
                    part2 += i;
                }
                break;
            case 7:
                if (countOccurences(id, idPart1) == 7)
                {
                    part2 += i;
                }
                break;
            case 8:
                if (countOccurences(id, idPart1) == 8 ||
                    countOccurences(id, idPart2) == 4 ||
                    countOccurences(id, idPart4) == 2)
                {
                    part2 += i;
                }
                break;
            case 9:
                if (countOccurences(id, idPart1) == 9 ||
                    countOccurences(id, idPart3) == 3)
                {
                    part2 += i;
                }
                break;
            case 10:
                if (countOccurences(id, idPart1) == 10 ||
                    countOccurences(id, idPart2) == 5 ||
                    countOccurences(id, idPart5) == 2)
                {
                    part2 += i;
                }
                break;

            default:
                break;
            }

            memset(id, 0, 64);
            memset(idPart1, 0, 64);
            memset(idPart2, 0, 64);
            memset(idPart3, 0, 64);
            memset(idPart4, 0, 64);
            memset(idPart5, 0, 64);
        }
    }

    printf("part 1: %lld\n", part1);
    printf("part 2: %lld\n", part2);

    return 0;
};