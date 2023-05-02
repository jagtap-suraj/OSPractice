// Q05. Implement a program for Dynamic partitioning placement algorithm - First fit

#include <stdio.h>
// #include <conio.h>

#define MAX_BLOCKS 50
#define MAX_PROCESSES 50

int main() 
{
    int n, m, i, j, pSize[MAX_PROCESSES], block[MAX_BLOCKS], allocation[MAX_PROCESSES];
    // clrscr();

    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the Sizes of memory blocks: ");
    for (i = 0; i < m; i++)
        scanf("%d", &block[i]);

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the Sizes of processes: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pSize[i]);

    for (i = 0; i < n; i++) 
    {
        allocation[i] = -1; // Initialize allocation array to -1 to indicate unallocated processes
        for (j = 0; j < m; j++) 
        {
            if (pSize[i] <= block[j]) 
            { // Check if process can fit in current block
                allocation[i] = j; // Allocate process to current block
                block[j] -= pSize[i]; // Update pSize of current block
                break;
            }
        }
    }

    printf("\nProcess\tpSize\tBlock\n");
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
Enter the pSizes of memory blocks:
100 500 200 300 600
Enter the number of processes: 4
Enter the pSizes of processes:
212 417 112 426

Process pSize    Block
1       212     1
2       417     5
3       112     3
4       426     Not allocated
*/