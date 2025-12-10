#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MACHINECOUNT 199

int pressButtons(int buttonCount, int buttonSize[], int buttons[][10], int machine, int deltaState[], int lightCount)
{
    int minPresses = 0;
    int workingDeltaState[lightCount];

    // 1 time
    for (int i = 0; i < buttonCount; i++)
    {
        // reset delta state
        for (int z = 0; z < lightCount; z++)
        {
            workingDeltaState[z] = deltaState[z];
        }

        // press the button
        for (int z = 0; z < buttonSize[i]; z++)
        {
            workingDeltaState[buttons[i][z]] = !workingDeltaState[buttons[i][z]];
        }

        // check delta state
        int wrongValues = 0;
        for (int z = 0; z < lightCount; z++)
        {
            if (workingDeltaState[z] != 0)
            {
                wrongValues++;
            }
        }

        if (wrongValues == 0)
        {
            minPresses = 1;
            break;
        }
    }

    if (minPresses == 1)
    {
        return 1;
    }

    // 2 times
    for (int i = 0; i < buttonCount; i++)
    {
        for (int j = 0; j < buttonCount; j++)
        {
            for (int z = 0; z < lightCount; z++)
            {
                workingDeltaState[z] = deltaState[z];
            }

            for (int z = 0; z < buttonSize[i]; z++)
            {
                workingDeltaState[buttons[i][z]] = !workingDeltaState[buttons[i][z]];
            }

            for (int z = 0; z < buttonSize[j]; z++)
            {
                workingDeltaState[buttons[j][z]] = !workingDeltaState[buttons[j][z]];
            }

            int wrongValues = 0;
            for (int z = 0; z < lightCount; z++)
            {
                if (workingDeltaState[z] != 0)
                {
                    wrongValues++;
                }
            }

            if (wrongValues == 0)
            {
                minPresses = 2;
                break;
            }
        }
        if (minPresses == 2)
            break;
    }

    if (minPresses == 2)
    {
        return 2;
    }

    // 3 times
    for (int i = 0; i < buttonCount; i++)
    {
        for (int j = 0; j < buttonCount; j++)
        {
            for (int k = 0; k < buttonCount; k++)
            {
                for (int z = 0; z < lightCount; z++)
                {
                    workingDeltaState[z] = deltaState[z];
                }

                for (int z = 0; z < buttonSize[i]; z++)
                {
                    workingDeltaState[buttons[i][z]] = !workingDeltaState[buttons[i][z]];
                }

                for (int z = 0; z < buttonSize[j]; z++)
                {
                    workingDeltaState[buttons[j][z]] = !workingDeltaState[buttons[j][z]];
                }

                for (int z = 0; z < buttonSize[k]; z++)
                {
                    workingDeltaState[buttons[k][z]] = !workingDeltaState[buttons[k][z]];
                }

                int wrongValues = 0;
                for (int z = 0; z < lightCount; z++)
                {
                    if (workingDeltaState[z] != 0)
                    {
                        wrongValues++;
                    }
                }

                if (wrongValues == 0)
                {
                    minPresses = 3;
                    break;
                }
            }
            if (minPresses == 3)
                break;
        }
        if (minPresses == 3)
            break;
    }

    if (minPresses == 3)
    {
        return 3;
    }

    // 4 times
    for (int i = 0; i < buttonCount; i++)
    {
        for (int j = 0; j < buttonCount; j++)
        {
            for (int k = 0; k < buttonCount; k++)
            {
                for (int l = 0; l < buttonCount; l++)
                {
                    for (int z = 0; z < lightCount; z++)
                    {
                        workingDeltaState[z] = deltaState[z];
                    }

                    for (int z = 0; z < buttonSize[i]; z++)
                    {
                        workingDeltaState[buttons[i][z]] = !workingDeltaState[buttons[i][z]];
                    }

                    for (int z = 0; z < buttonSize[j]; z++)
                    {
                        workingDeltaState[buttons[j][z]] = !workingDeltaState[buttons[j][z]];
                    }

                    for (int z = 0; z < buttonSize[k]; z++)
                    {
                        workingDeltaState[buttons[k][z]] = !workingDeltaState[buttons[k][z]];
                    }

                    for (int z = 0; z < buttonSize[l]; z++)
                    {
                        workingDeltaState[buttons[l][z]] = !workingDeltaState[buttons[l][z]];
                    }

                    int wrongValues = 0;
                    for (int z = 0; z < lightCount; z++)
                    {
                        if (workingDeltaState[z] != 0)
                        {
                            wrongValues++;
                        }
                    }

                    if (wrongValues == 0)
                    {
                        minPresses = 4;
                        break;
                    }
                }
                if (minPresses == 4)
                    break;
            }
            if (minPresses == 4)
                break;
        }
        if (minPresses == 4)
            break;
    }

    if (minPresses == 4)
    {
        return 4;
    }

    // five times
    for (int i = 0; i < buttonCount; i++)
    {
        for (int j = 0; j < buttonCount; j++)
        {
            for (int k = 0; k < buttonCount; k++)
            {
                for (int l = 0; l < buttonCount; l++)
                {
                    for (int m = 0; m < buttonCount; m++)
                    {
                        for (int z = 0; z < lightCount; z++)
                        {
                            workingDeltaState[z] = deltaState[z];
                        }

                        for (int z = 0; z < buttonSize[i]; z++)
                        {
                            workingDeltaState[buttons[i][z]] = !workingDeltaState[buttons[i][z]];
                        }

                        for (int z = 0; z < buttonSize[j]; z++)
                        {
                            workingDeltaState[buttons[j][z]] = !workingDeltaState[buttons[j][z]];
                        }

                        for (int z = 0; z < buttonSize[k]; z++)
                        {
                            workingDeltaState[buttons[k][z]] = !workingDeltaState[buttons[k][z]];
                        }

                        for (int z = 0; z < buttonSize[l]; z++)
                        {
                            workingDeltaState[buttons[l][z]] = !workingDeltaState[buttons[l][z]];
                        }

                        for (int z = 0; z < buttonSize[m]; z++)
                        {
                            workingDeltaState[buttons[m][z]] = !workingDeltaState[buttons[m][z]];
                        }

                        int wrongValues = 0;
                        for (int z = 0; z < lightCount; z++)
                        {
                            if (workingDeltaState[z] != 0)
                            {
                                wrongValues++;
                            }
                        }

                        if (wrongValues == 0)
                        {
                            minPresses = 5;
                            break;
                        }
                    }
                    if (minPresses == 5)
                        break;
                }
                if (minPresses == 5)
                    break;
            }
            if (minPresses == 5)
                break;
        }
        if (minPresses == 5)
            break;
    }

    if (minPresses == 5)
    {
        return 5;
    }

    // six times
    for (int i = 0; i < buttonCount; i++)
    {
        for (int j = 0; j < buttonCount; j++)
        {
            for (int k = 0; k < buttonCount; k++)
            {
                for (int l = 0; l < buttonCount; l++)
                {
                    for (int m = 0; m < buttonCount; m++)
                    {
                        for (int n = 0; n < buttonCount; n++)
                        {
                            for (int z = 0; z < lightCount; z++)
                            {
                                workingDeltaState[z] = deltaState[z];
                            }

                            for (int z = 0; z < buttonSize[i]; z++)
                            {
                                workingDeltaState[buttons[i][z]] = !workingDeltaState[buttons[i][z]];
                            }

                            for (int z = 0; z < buttonSize[j]; z++)
                            {
                                workingDeltaState[buttons[j][z]] = !workingDeltaState[buttons[j][z]];
                            }

                            for (int z = 0; z < buttonSize[k]; z++)
                            {
                                workingDeltaState[buttons[k][z]] = !workingDeltaState[buttons[k][z]];
                            }

                            for (int z = 0; z < buttonSize[l]; z++)
                            {
                                workingDeltaState[buttons[l][z]] = !workingDeltaState[buttons[l][z]];
                            }

                            for (int z = 0; z < buttonSize[m]; z++)
                            {
                                workingDeltaState[buttons[m][z]] = !workingDeltaState[buttons[m][z]];
                            }

                            for (int z = 0; z < buttonSize[n]; z++)
                            {
                                workingDeltaState[buttons[n][z]] = !workingDeltaState[buttons[n][z]];
                            }

                            int wrongValues = 0;
                            for (int z = 0; z < lightCount; z++)
                            {
                                if (workingDeltaState[z] != 0)
                                {
                                    wrongValues++;
                                }
                            }

                            if (wrongValues == 0)
                            {
                                minPresses = 6;
                                break;
                            }
                        }
                        if (minPresses == 6)
                            break;
                    }
                    if (minPresses == 6)
                        break;
                }
                if (minPresses == 6)
                    break;
            }
            if (minPresses == 6)
                break;
        }
    }

    if (minPresses == 6)
    {
        return 6;
    }

    // seven times
    for (int i = 0; i < buttonCount; i++)
    {
        for (int j = 0; j < buttonCount; j++)
        {
            for (int k = 0; k < buttonCount; k++)
            {
                for (int l = 0; l < buttonCount; l++)
                {
                    for (int m = 0; m < buttonCount; m++)
                    {
                        for (int n = 0; n < buttonCount; n++)
                        {
                            for (int o = 0; o < buttonCount; o++)
                            {
                                for (int z = 0; z < lightCount; z++)
                                {
                                    workingDeltaState[z] = deltaState[z];
                                }

                                for (int z = 0; z < buttonSize[i]; z++)
                                {
                                    workingDeltaState[buttons[i][z]] = !workingDeltaState[buttons[i][z]];
                                }

                                for (int z = 0; z < buttonSize[j]; z++)
                                {
                                    workingDeltaState[buttons[j][z]] = !workingDeltaState[buttons[j][z]];
                                }

                                for (int z = 0; z < buttonSize[k]; z++)
                                {
                                    workingDeltaState[buttons[k][z]] = !workingDeltaState[buttons[k][z]];
                                }

                                for (int z = 0; z < buttonSize[l]; z++)
                                {
                                    workingDeltaState[buttons[l][z]] = !workingDeltaState[buttons[l][z]];
                                }

                                for (int z = 0; z < buttonSize[m]; z++)
                                {
                                    workingDeltaState[buttons[m][z]] = !workingDeltaState[buttons[m][z]];
                                }

                                for (int z = 0; z < buttonSize[n]; z++)
                                {
                                    workingDeltaState[buttons[n][z]] = !workingDeltaState[buttons[n][z]];
                                }

                                for (int z = 0; z < buttonSize[o]; z++)
                                {
                                    workingDeltaState[buttons[o][z]] = !workingDeltaState[buttons[o][z]];
                                }

                                int wrongValues = 0;
                                for (int z = 0; z < lightCount; z++)
                                {
                                    if (workingDeltaState[z] != 0)
                                    {
                                        wrongValues++;
                                    }
                                }

                                if (wrongValues == 0)
                                {
                                    minPresses = 7;
                                    break;
                                }
                            }
                            if (minPresses == 7)
                                break;
                        }
                        if (minPresses == 7)
                            break;
                    }
                    if (minPresses == 7)
                        break;
                }
                if (minPresses == 7)
                    break;
            }
            if (minPresses == 7)
                break;
        }
    }

    if (minPresses == 7)
    {
        return 7;
    }

    return 0;
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

    // for (int i = 0; i < MACHINECOUNT; i++)
    // {
    //     printf("[");
    //     for (int j = 0; j < lightCount[i]; j++)
    //     {
    //         printf("%d", indicators[i][j]);
    //     }
    //     printf("] ");

    //     for (int j = 0; j < buttonCount[i]; j++)
    //     {
    //         printf("(");
    //         for (int k = 0; k < buttonSize[i][j]; k++)
    //         {
    //             printf("%d,", buttons[i][j][k]);
    //         }
    //         printf(") ");
    //     }

    //     printf("%d", buttonCount[i]);

    //     printf("\n");
    // }

    for (int i = 0; i < MACHINECOUNT; i++)
    {
        int deltaState[lightCount[i]];
        int workingDeltaState[lightCount[i]];

        for (int j = 0; j < lightCount[i]; j++)
        {
            deltaState[j] = indicators[i][j];
        }

        int presses = pressButtons(buttonCount[i], buttonSize[i], buttons[i], i, deltaState, lightCount[i]);

        if (presses == 0)
        {
            printf("machine %d presses %d\n\n", i, presses);
        }

        part1Count += presses;
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}