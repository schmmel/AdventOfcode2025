#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    long long part1Count = 0;
    long long part2Count = 0;

    long long part1Problems[1000][4];

    char operators[1000];
    long long operationLength[1000];

    int problemCount = 0;

    char lines[4][6400];
    char operatorLine[6400];

    fgets(lines[0], sizeof(lines[0]), fptr);
    fgets(lines[1], sizeof(lines[1]), fptr);
    fgets(lines[2], sizeof(lines[2]), fptr);
    fgets(lines[3], sizeof(lines[3]), fptr);
    fgets(operatorLine, sizeof(operatorLine), fptr);

    int length = 0;
    for (int i = 0; i < strlen(operatorLine); i++)
    {
        if (operatorLine[i] == ' ')
        {
            length++;
        }

        if (operatorLine[i] == '*' || operatorLine[i] == '+')
        {
            operationLength[problemCount - 1] = length;

            length = 0;

            operators[problemCount] = operatorLine[i];

            problemCount++;
        }

        if (operatorLine[i] == '\n')
        {
            operationLength[problemCount - 1] = length + 1;

            length = 0;
        }
    }

    // part 1
    for (int i = 0; i < 4; i++)
    {
        char *part1 = lines[i];

        problemCount = 0;

        while (sscanf(part1, "%lld", &part1Problems[problemCount][i]) == 1)
        {
            problemCount++;

            while (*part1 && *part1 != ' ' && *part1 != '\t')
            {
                part1++;
            }
            while (*part1 == ' ' || *part1 == '\t')
            {
                part1++;
            }
        }
    }

    for (int i = 0; i < problemCount; i++)
    {
        if (operators[i] == '*')
        {
            part1Count += part1Problems[i][0] * part1Problems[i][1] * part1Problems[i][2] * part1Problems[i][3];
        }
        else if (operators[i] == '+')
        {
            part1Count += part1Problems[i][0] + part1Problems[i][1] + part1Problems[i][2] + part1Problems[i][3];
        }

        // printf("%lld %lld %lld %lld %c\n", part1Problems[i][0], part1Problems[i][1], part1Problems[i][2], part1Problems[i][3], operators[i]);
    }

    // part 2
    long long j = 0;

    for (int i = 0; i < strlen(operators); i++)
    {
        long long numbers[4];
        int numberCount = 0;

        // printf("%d %d: ", i, operationLength[i]);
        char buf[4];

        // printf("%c %c %c %c: ", lines[0][j], lines[1][j], lines[2][j], lines[3][j]);

        for (long long k = 0; k < operationLength[i]; k++)
        {
            buf[0] = lines[0][j + k];
            buf[1] = lines[1][j + k];
            buf[2] = lines[2][j + k];
            buf[3] = lines[3][j + k];
            numbers[k] = atoll(buf);
        }

        j += operationLength[i] + 1;

        numberCount = operationLength[i];

        switch (numberCount)
        {
        case 2:
            if (operators[i] == '*')
            {
                part2Count += numbers[0] * numbers[1];
            }
            else if (operators[i] == '+')
            {
                part2Count += numbers[0] + numbers[1];
            }
            break;
        case 3:
            if (operators[i] == '*')
            {
                part2Count += numbers[0] * numbers[1] * numbers[2];
            }
            else if (operators[i] == '+')
            {
                part2Count += numbers[0] + numbers[1] + numbers[2];
            }
            break;
        case 4:
            if (operators[i] == '*')
            {
                part2Count += numbers[0] * numbers[1] * numbers[2] * numbers[3];
            }
            else if (operators[i] == '+')
            {
                part2Count += numbers[0] + numbers[1] + numbers[2] + numbers[3];
            }
            break;
        }

        // printf("\n");
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);
    // printf("%lld %lld %lld %lld %c\n", part2Problems[0][0][0], part2Problems[0][0][1], part2Problems[0][0][2], part2Problems[0][0][3], operators[0]);

    return 0;
}