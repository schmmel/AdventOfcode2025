#include <stdio.h>
#include <string.h>

long long part1Count = 0;
long long part2Count = 0;

char manifold[200][200];

int beams[200];
long long beamTimeline[200][200];

int main()
{
    FILE *fptr = fopen("input.txt", "r");
    memset(beams, 0, sizeof(beams));

    int i = 0;
    while (fgets(manifold[i], sizeof(manifold[i]), fptr))
    {
        // printf("%s", manifold[i]);
        i++;
    }

    // part 1
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < strlen(manifold[i]); j++)
        {
            if (manifold[i][j] == 'S')
            {
                beams[j] = 1;
            }

            if (manifold[i][j] == '^' && beams[j] == 1)
            {
                beams[j] = 0;
                beams[j - 1] = 1;
                beams[j + 1] = 1;
                part1Count++;
            }
        }

        // visualiser
        // for (int j = 0; j < strlen(manifold[i]); j++)
        // {
        //     if ((beams[j] == 1 && manifold[i][j] != '^'))
        //     {
        //         printf("|");
        //     }
        //     else
        //     {
        //         printf("%c", manifold[i][j]);
        //     }
        // }
    }

    // part 2
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < strlen(manifold[i]); j++)
        {
            if (manifold[i][j] == 'S')
            {
                beamTimeline[1][j] += 1;
            }

            if (manifold[i][j] == '^' && beamTimeline[i - 1][j] != 0)
            {
                beamTimeline[i][j - 1] += beamTimeline[i - 1][j];
                beamTimeline[i][j + 1] += beamTimeline[i - 1][j];
            }

            if (manifold[i][j] != '^' && beamTimeline[i - 1][j] != 0 && i != 0)
            {
                beamTimeline[i][j] += beamTimeline[i - 1][j];
            }
        }

        // visualiser
        // for (int j = 0; j < strlen(manifold[i]); j++)
        // {
        //     if ((manifold[i][j] != '^' && manifold[i][j] != 'S' && beamTimeline[i][j] != 0))
        //     {
        //         printf("%lld", beamTimeline[i][j]);
        //     }
        //     else
        //     {
        //         printf("%c", manifold[i][j]);
        //     }
        // }
    }

    for (int i = 0; i < 200; i++)
    {
        part2Count += beamTimeline[141][i];
    }

    printf("part 1: %lld\n", part1Count);
    printf("part 2: %lld\n", part2Count);

    return 0;
}
