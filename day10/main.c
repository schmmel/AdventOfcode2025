#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MACHINECOUNT 3

// part 1 function
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

#define MAXDIMENSIONS 10
#define MAXOPTIONS 13
#define MAXQUEUE 1000000

int dimensions;

__int128_t visitedKey[MAXQUEUE];
int visitedStepsTaken[MAXQUEUE];
int visitedCount = 0;

__int128_t encode(int *coordinates)
{
    __int128_t key = 0;
    for (int d = 0; d < dimensions; d++)
    {
        key = key * 300 + coordinates[d];
    }
    return key;
}

struct Node
{
    int coordinates[MAXDIMENSIONS];
    int stepsTaken;
    int score;
};

struct Node queue[MAXQUEUE];
int queueSize = 0;

int heuristic(int *coordinates, int *destination)
{
    int h = 0;
    for (int d = 0; d < dimensions; d++)
    {
        int need = destination[d] - coordinates[d];
        if (need > h)
        {
            h = need;
        }
    }
    return h;
}

void enqueue(struct Node n)
{
    int index = queueSize++;
    queue[index] = n;

    while (index > 0)
    {
        int parentIndex = (index - 1) / 2;
        if (queue[parentIndex].score <= queue[index].score)
        {
            break;
        }

        struct Node temp = queue[parentIndex];
        queue[parentIndex] = queue[index];
        queue[index] = temp;
        index = parentIndex;
    }
}

struct Node dequeue()
{
    struct Node min = queue[0];
    queueSize--;
    queue[0] = queue[queueSize];

    int index = 0;
    while (1)
    {
        int leftIndex = index * 2 + 1;
        int rightIndex = index * 2 + 2;
        int smallest = index;

        if (leftIndex < queueSize && queue[leftIndex].score < queue[smallest].score)
        {
            smallest = leftIndex;
        }
        if (rightIndex < queueSize && queue[rightIndex].score < queue[smallest].score)
        {
            smallest = rightIndex;
        }

        if (smallest == index)
        {
            break;
        }

        struct Node temp = queue[index];
        queue[index] = queue[smallest];
        queue[smallest] = temp;

        index = smallest;
    }

    return min;
}

int exceedsDestination(int *coordinates, int *destination)
{
    for (int d = 0; d < dimensions; d++)
    {
        if (coordinates[d] > destination[d])
        {
            return 1;
        }
    }
    return 0;
}

int compareCoords(int *coordinatesA, int *coordinatesB)
{
    for (int d = 0; d < dimensions; d++)
    {
        if (coordinatesA[d] != coordinatesB[d])
        {
            return 0;
        }
    }
    return 1;
}

int AStar(int stepOptions, int steps[MAXOPTIONS][MAXDIMENSIONS], int *start, int *destination)
{
    queueSize = 0;
    visitedCount = 0;

    struct Node startNode;
    memcpy(startNode.coordinates, start, sizeof(int) * dimensions);
    startNode.stepsTaken = 0;
    startNode.score = heuristic(startNode.coordinates, destination);

    enqueue(startNode);

    // int current[MAXDIMENSIONS];
    int stepCount = 0;

    while (queueSize > 0)
    {
        struct Node current = dequeue();

        // printf("%d %d\n", queueSize, current.score);

        if (compareCoords(current.coordinates, destination))
        {
            return current.stepsTaken;
        }

        for (int i = 0; i < stepOptions; i++)
        {
            int neighbor[MAXDIMENSIONS];

            for (int d = 0; d < dimensions; d++)
            {
                neighbor[d] = current.coordinates[d] + steps[i][d];
            }

            if (exceedsDestination(neighbor, destination))
            {
                continue;
            }

            __int128_t key = encode(neighbor);
            int alreadyVisited = 0;

            for (int j = 0; j < visitedCount; j++)
            {
                if (visitedKey[j] == key && visitedStepsTaken[j] <= current.stepsTaken + 1)
                {
                    alreadyVisited = 1;
                    break;
                }
            }

            if (!alreadyVisited)
            {
                visitedKey[visitedCount] = key;
                visitedStepsTaken[visitedCount] = current.stepsTaken + 1;
                visitedCount++;

                struct Node neighborNode;
                memcpy(neighborNode.coordinates, neighbor, sizeof(int) * dimensions);
                neighborNode.stepsTaken = current.stepsTaken + 1;
                neighborNode.score = neighborNode.stepsTaken + heuristic(neighbor, destination);

                enqueue(neighborNode);
            }
        }
    }

    return -1;
}

int joltageSteps(int machine, int lightCount, int joltage[], int steps[][10], int stepOptions, int stepDimensions[])
{
    int formattedSteps[MAXOPTIONS][MAXDIMENSIONS] = {0};
    int start[MAXDIMENSIONS] = {0};
    int destination[MAXDIMENSIONS] = {0};

    for (int i = 0; i < lightCount; i++)
    {
        destination[i] = joltage[i];
    }

    for (int i = 0; i < stepOptions; i++)
    {
        for (int j = 0; j < stepDimensions[i]; j++)
        {
            formattedSteps[i][steps[i][j]] = 1;
        }
    }

    // printf("%d \n", machine);

    // printf("  start: ");
    // for (int d = 0; d < dimensions; d++)
    // {
    //     printf("000 ");
    // }
    // printf("end: ");
    // for (int i = 0; i < lightCount; i++)
    // {
    //     printf("%03d ", joltage[i]);
    // }
    // printf("\noptions: ");

    // for (int i = 0; i < stepOptions; i++)
    // {
    //     printf("(");
    //     for (int j = 0; j < stepDimensions[i]; j++)
    //     {
    //         printf("%d,", steps[i][j]);
    //     }
    //     printf(") ");
    // }

    // printf("\n");

    // for (int i = 0; i < stepOptions; i++)
    // {
    //     printf("(");
    //     for (int j = 0; j < MAXDIMENSIONS; j++)
    //     {
    //         printf("%d,", formattedSteps[i][j]);
    //     }
    //     printf(") ");
    // }

    // printf("\n");

    dimensions = lightCount;
    return AStar(stepOptions, formattedSteps, start, destination);
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

    int joltage[MACHINECOUNT][10];

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

        bufferIndex++;

        int joltageIndex = 0;
        char joltageBuffer[4];
        int jb = 0;
        while (buffer[bufferIndex] != '}')
        {
            if (buffer[bufferIndex] != ',')
            {
                joltageBuffer[jb] = buffer[bufferIndex];
                jb++;
            }
            else
            {
                joltage[i][joltageIndex] = atoi(joltageBuffer);
                memset(joltageBuffer, 0, 4);
                joltageIndex++;
                jb = 0;
            }
            bufferIndex++;
        }

        joltage[i][joltageIndex] = atoi(joltageBuffer);
    }

    // // printer
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

    //     printf("{");
    //     for (int j = 0; j < lightCount[i]; j++)
    //     {
    //         printf("%d,", joltage[i][j]);
    //     }
    //     printf("}");

    //     // printf("%d", buttonCount[i]);

    //     printf("\n");
    // }
    // printf("\n");

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

        int stepsTaken = joltageSteps(i, lightCount[i], joltage[i], buttons[i], buttonCount[i], buttonSize[i]);

        printf("steps: %d\n", stepsTaken);

        part2Count += stepsTaken;
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}