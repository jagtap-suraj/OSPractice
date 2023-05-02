// Q06. Implement a program for Dynamic partitioning placement algorithm - Best fit

#include <stdio.h>
#include <limits.h>
// #include <conio.h>

#define MAX_BLOCKS 50
#define MAX_PROCESSES 50

int main() 
{
    int n, m, i, j, pSize[MAX_PROCESSES], block[MAX_BLOCKS], allocation[MAX_PROCESSES], bestIndex, bestFit;
    // clrscr();

    // Initialize allocation array to -1 to indicate unallocated processes
    // for (i = 0; i < MAX_PROCESSES; i++) 
    //     allocation[i] = -1;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the sizes of memory blocks: ");
    for (i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the sizes of processes: ");
    for (i = 0; i < n; i++) 
        scanf("%d", &pSize[i]);

    for (i = 0; i < n; i++) 
    {
        allocation[i] = -1;
        bestIndex = -1;
        bestFit = INT_MAX;
        for (j = 0; j < m; j++) 
        {
            if (pSize[i] <= block[j] && block[j] < bestFit) 
            {
                bestIndex = j;
                bestFit = block[j];
            }
        }
        if (bestIndex != -1) 
        {
            allocation[i] = bestIndex;
            block[bestIndex] -= pSize[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d\t%d\t", i+1, pSize[i]);
        if (allocation[i] != -1) 
            printf("%d\n", allocation[i]+1);
        else 
            printf("Not allocated\n");
    }

    // getch();
    return 0;
}



/*Output:
Enter the number of memory blocks: 5
Enter the sizes of memory blocks: 100 500 200 300 600
Enter the number of processes: 4
Enter the sizes of processes: 212 417 112 426

Process Size    Block
1       212     4
2       417     2
3       112     3
4       426     5
*/