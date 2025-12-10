#include <stdio.h>
#include <stdlib.h>

#define ROWS 200
#define COLUMNS 100

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    int part1 = 0;
    long long part2 = 0;

    int batteries[ROWS][COLUMNS];

    // populate batteries
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            fscanf(fptr, "%1d", &batteries[i][j]);
            // printf("%d", batteries[i][j]);
        }
        // printf("\n");
    }

    for (int i = 0; i < ROWS; i++)
    {

        int part1FirstNumber = 0;
        int part1FirstNumberLocation;
        int part1SecondNumber = 0;

        for (int j = 0; j < COLUMNS - 1; j++)
        {
            if (batteries[i][j] > part1FirstNumber)
            {
                part1FirstNumber = batteries[i][j];
                part1FirstNumberLocation = j;
            }
        }

        for (int j = part1FirstNumberLocation + 1; j < COLUMNS; j++)
        {
            if (batteries[i][j] > part1SecondNumber)
            {
                part1SecondNumber = batteries[i][j];
            }
        }

        // part 2
        int firstNumber = 0;
        int firstNumberLocation;
        int secondNumber = 0;
        int secondNumberLocation;
        int thirdNumber = 0;
        int thirdNumberLocation;
        int fourthNumber = 0;
        int fourthNumberLocation;
        int fifthNumber = 0;
        int fifthNumberLocation;
        int sixthNumber = 0;
        int sixthNumberLocation;
        int seventhNumber = 0;
        int seventhNumberLocation;
        int eigthNumber = 0;
        int eigthNumberLocation;
        int ninthNumber = 0;
        int ninthNumberLocation;
        int tenthNumber = 0;
        int tenthNumberLocation;
        int eleventhNumber = 0;
        int eleventhNumberLocation;
        int twelfthNumber = 0;

        for (int j = 0; j < COLUMNS - 11; j++)
        {
            if (batteries[i][j] > firstNumber)
            {
                firstNumber = batteries[i][j];
                firstNumberLocation = j;
            }
        }

        for (int j = firstNumberLocation + 1; j < COLUMNS - 10; j++)
        {
            if (batteries[i][j] > secondNumber)
            {
                secondNumber = batteries[i][j];
                secondNumberLocation = j;
            }
        }

        for (int j = secondNumberLocation + 1; j < COLUMNS - 9; j++)
        {
            if (batteries[i][j] > thirdNumber)
            {
                thirdNumber = batteries[i][j];
                thirdNumberLocation = j;
            }
        }

        for (int j = thirdNumberLocation + 1; j < COLUMNS - 8; j++)
        {
            if (batteries[i][j] > fourthNumber)
            {
                fourthNumber = batteries[i][j];
                fourthNumberLocation = j;
            }
        }

        for (int j = fourthNumberLocation + 1; j < COLUMNS - 7; j++)
        {
            if (batteries[i][j] > fifthNumber)
            {
                fifthNumber = batteries[i][j];
                fifthNumberLocation = j;
            }
        }

        for (int j = fifthNumberLocation + 1; j < COLUMNS - 6; j++)
        {
            if (batteries[i][j] > sixthNumber)
            {
                sixthNumber = batteries[i][j];
                sixthNumberLocation = j;
            }
        }

        for (int j = sixthNumberLocation + 1; j < COLUMNS - 5; j++)
        {
            if (batteries[i][j] > seventhNumber)
            {
                seventhNumber = batteries[i][j];
                seventhNumberLocation = j;
            }
        }

        for (int j = seventhNumberLocation + 1; j < COLUMNS - 4; j++)
        {
            if (batteries[i][j] > eigthNumber)
            {
                eigthNumber = batteries[i][j];
                eigthNumberLocation = j;
            }
        }

        for (int j = eigthNumberLocation + 1; j < COLUMNS - 3; j++)
        {
            if (batteries[i][j] > ninthNumber)
            {
                ninthNumber = batteries[i][j];
                ninthNumberLocation = j;
            }
        }

        for (int j = ninthNumberLocation + 1; j < COLUMNS - 2; j++)
        {
            if (batteries[i][j] > tenthNumber)
            {
                tenthNumber = batteries[i][j];
                tenthNumberLocation = j;
            }
        }

        for (int j = tenthNumberLocation + 1; j < COLUMNS - 1; j++)
        {
            if (batteries[i][j] > eleventhNumber)
            {
                eleventhNumber = batteries[i][j];
                eleventhNumberLocation = j;
            }
        }

        for (int j = eleventhNumberLocation + 1; j < COLUMNS; j++)
        {
            if (batteries[i][j] > twelfthNumber)
            {
                twelfthNumber = batteries[i][j];
            }
        }

        // printf("%d %d\n", part1FirstNumber, part1SecondNumber);

        part1 += part1FirstNumber * 10 + part1SecondNumber;

        // printf("%d %d %d %d %d %d %d %d %d %d %d %d \n", firstNumber, secondNumber, thirdNumber, fourthNumber, fifthNumber, sixthNumber, seventhNumber, eigthNumber, ninthNumber, tenthNumber, eleventhNumber, twelfthNumber);
        // printf("%lld\n", ((((((((((firstNumber * 10 + secondNumber) * 10 + thirdNumber) * 10 + fourthNumber) * 10 + fifthNumber) * 10 + sixthNumber) * 10 + seventhNumber) * 10 + eigthNumber) * 10 + ninthNumber) * 10 + tenthNumber) * 10 + eleventhNumber) * 10 + twelfthNumber);

        char resultBuffer[32];

        sprintf(resultBuffer, "%d%d%d%d%d%d%d%d%d%d%d%d", firstNumber, secondNumber, thirdNumber, fourthNumber, fifthNumber, sixthNumber, seventhNumber, eigthNumber, ninthNumber, tenthNumber, eleventhNumber, twelfthNumber);

        long long result = atoll(resultBuffer);

        // printf("%lld\n", result);

        part2 += result;
    }

    printf("part 1: %d\n", part1);
    printf("part 2: %lld\n", part2);

    return 0;
}