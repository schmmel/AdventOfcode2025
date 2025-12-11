#include <stdio.h>
#include <string.h>

#define DEVICECOUNT 611

struct Device
{
    char name[4];
    char outputs[20][4];
    int outputCount;
};

struct Device devices[DEVICECOUNT];

struct Device* findDevice(char name[4])
{
    for (int i = 0; i < DEVICECOUNT; i++)
    {
        if (strcmp(devices[i].name, name) == 0)
        {
            return &devices[i];
        }
    }
}

int findDeviceIndex(char name[4])
{
    for (int i = 0; i < DEVICECOUNT; i++)
    {
        if (strcmp(devices[i].name, name) == 0)
        {
            return i;
        }
    }
}

// part 1
int paths = 0;

int traverseTree(struct Device* you)
{
    if (strcmp(you->outputs[0], "out") == 0)
    {
        paths++;
    }
    else
    {
        for (int i = 0; i < you->outputCount; i++)
        {
            traverseTree(findDevice(you->outputs[i]));
        }
    }

    return paths;
}

// part 2
long long memory[DEVICECOUNT][4];

long long countPathsThroughDACFFT(int index, int visitedMask)
{
    if (memory[index][visitedMask] != -1)
    {
        return memory[index][visitedMask];
    }

    struct Device* device = &devices[index];
    int newMask = visitedMask;

    if (strcmp(device->name, "dac") == 0)
    {
        newMask |= 0b01;
    }
    if (strcmp(device->name, "fft") == 0)
    {
        newMask |= 0b10;
    }
    
    long long total = 0;

    if (strcmp(device->outputs[0], "out") == 0)
    {
        if (newMask == 0b11)
        {
            total = 1;
        }
    }
    else
    {
        for (int i = 0; i < device->outputCount; i++)
        {
            int nextIndex = findDeviceIndex(device->outputs[i]);

            total += countPathsThroughDACFFT(nextIndex, newMask);
        }
    }
    
    memory[index][visitedMask] = total;
    return total;
}

int main()
{
    for (int i = 0; i < DEVICECOUNT; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            memory[i][j] = -1;
        }
    }
    
    FILE *fptr = fopen("input.txt", "r");

    long long part1Count = 0;
    long long part2Count = 0;

    char buffer[640];

    for (int i = 0; i < DEVICECOUNT; i++)
    {
        devices[i].outputCount = 0;

        fgets(buffer, sizeof(buffer), fptr);

        char *p = buffer;

        sscanf(p, "%3s:", &devices[i].name);
        p += 5;

        while (*p)
        {
            sscanf(p, " %3s", devices[i].outputs[devices[i].outputCount]);
            devices[i].outputCount++;
            p += 4;
        }

        // printf("%s: ", devices[i].name);

        // for (int j = 0; j < devices[i].outputCount; j++)
        // {
        //     printf("%s ", devices[i].outputs[j]);
        // }

        // printf("\n");
    }

    part1Count = traverseTree(findDevice("you"));
    part2Count = countPathsThroughDACFFT(findDeviceIndex("svr"), 0);

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}