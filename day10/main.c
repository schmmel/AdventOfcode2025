#include <stdio.h>
#include <stdlib.h>

#define MACHINECOUNT 199

void nextPermutation(int buttonOrder[], int buttonCount)
{
    int i = buttonCount - 2;
    while (i >= 0 && buttonOrder[i] >= buttonOrder[i + 1])
    {
        i--;
    }

    // last permutation surpassed
    if (i < 0)
    {
        // reset to original
        for (int j = 0; j < buttonCount; j++)
        {
            buttonOrder[j] = j;
        }

        return;
    }

    int j = buttonCount - 1;
    while (buttonOrder[j] <= buttonOrder[i])
    {
        j--;
    }

    // swap
    int temp = buttonOrder[i];
    buttonOrder[i] = buttonOrder[j];
    buttonOrder[j] = temp;

    int left = i + 1, right = buttonCount - 1;
    while (left < right)
    {
        // swap
        temp = buttonOrder[left];
        buttonOrder[left] = buttonOrder[right];
        buttonOrder[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    FILE *fptr = fopen("input.txt", "r");

    long long part1Count = 0;
    long long part2Count = 0;

    int lightCount[MACHINECOUNT] = {0};
    int indicators[MACHINECOUNT][10];

    int buttonCount[MACHINECOUNT] = {0};
    int buttonSize[MACHINECOUNT][32] = {0};
    int buttons[MACHINECOUNT][32][10];

    char buffer[640];

    for (int i = 0; i < MACHINECOUNT; i++)
    {
        fgets(buffer, sizeof(buffer), fptr);

        int bufferIndex = 1;
        while (buffer[bufferIndex] != ']')
        {
            indicators[i][lightCount[i]] = (buffer[bufferIndex] == '#') ? 1 : 0;

            lightCount[i]++;
            bufferIndex++;
        }

        bufferIndex += 2;

        int buttonFound = 0;

        while (buffer[bufferIndex] != '{')
        {
            if (buttonFound == 0)
            {
                if (buffer[bufferIndex] == '(')
                {
                    buttonFound = 1;
                }
            }
            else
            {
                if (buffer[bufferIndex] == ')')
                {
                    buttonFound = 0;
                    buttonCount[i]++;
                }
                else if (buffer[bufferIndex] != ',')
                {
                    buttons[i][buttonCount[i]][buttonSize[i][buttonCount[i]]] = atoi(&buffer[bufferIndex]);
                    buttonSize[i][buttonCount[i]]++;
                }
            }
            bufferIndex++;
        }
    }

    for (int i = 0; i < MACHINECOUNT; i++)
    {
        printf("[");
        for (int j = 0; j < lightCount[i]; j++)
        {
            printf("%d", indicators[i][j]);
        }
        printf("] ");

        for (int j = 0; j < buttonCount[i]; j++)
        {
            printf("(");
            for (int k = 0; k < buttonSize[i][j]; k++)
            {
                printf("%d,", buttons[i][j][k]);
            }
            printf(") ");
        }

        printf("%d", buttonCount[i]);

        printf("\n");
    }

    for (int i = 0; i < MACHINECOUNT; i++)
    {
        int minPresses = buttonCount[i];

        int deltaState[lightCount[i]];
        int workingDeltaState[lightCount[i]];

        for (int j = 0; j < lightCount[i]; j++)
        {
            deltaState[j] = indicators[i][j];
        }

        // for (int j = 0; j < lightCount[i]; j++)
        // {
        //     printf("%d", deltaState[j]);
        // }

        // printf("\n");

        // printf("%d\n", factorial(buttonCount[i]));

        long long totalPermutations = 1;
        int min = (buttonCount[i] < 11) ? buttonCount[i] : 11;
        // printf("%d\n", min);
        for (int j = 1; j <= min; j++)
        {
            totalPermutations *= j;
        }

        int buttonOrder[buttonCount[i]];

        for (int j = 0; j < buttonCount[i]; j++)
        {
            buttonOrder[j] = j;
        }

        for (long long j = 0; j < totalPermutations; j++)
        {
            for (int k = 0; k < lightCount[i]; k++)
            {
                workingDeltaState[k] = deltaState[k];
            }

            for (int k = 0; k < buttonCount[i] && k < minPresses; k++)
            {
                // printf("%d\n", buttonOrder[k]);

                for (int l = 0; l < buttonSize[i][buttonOrder[k]]; l++)
                {
                    workingDeltaState[buttons[i][buttonOrder[k]][l]] = !workingDeltaState[buttons[i][buttonOrder[k]][l]];
                    // printf("%d,", buttons[i][buttonOrder[k][l]);
                }

                int wrongValues = 0;
                for (int l = 0; l < lightCount[i]; l++)
                {
                    if (workingDeltaState[l] != 0)
                    {
                        wrongValues++;
                    }

                    // printf("%d ", workingDeltaState[l]);
                }

                // printf("\n");

                if (wrongValues == 0)
                {
                    minPresses = k + 1;
                    // printf("correct %d\n", minPresses);
                    break;
                }

                // printf("\n");
            }
            // printf("\n");

            nextPermutation(buttonOrder, buttonCount[i]);
        }

        printf("%d %d\n", i, minPresses);

        part1Count += minPresses;
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}