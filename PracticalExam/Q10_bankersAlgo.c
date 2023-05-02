// Q10. Write a program to demonstrate the concept of deadlock avoidance through Banker’s Algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include<conio.h>


/*
Steps:
1. Input the number of processes, number of resources, allocation matrix, max matrix and available
2. Calculate the need matrix
3. Check if the need matrix is less than the available matrix
4. If yes, then allocate the resources and mark the process as finished
5. Repeat steps 3 and 4 until all the processes are finished
6. If all the processes are finished, then the system is in safe state
*/

int main()
{
    int n, m, i, j, k, l, temp, count = 0, index = 0;
    int allocation[100][100], max[100][100], need[100][100], available[100], work[100];
    int finish[100] = {0};
    bool flag = true;
    // clrscr();

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    printf("Enter the allocation matrix: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    
    printf("Enter the max matrix: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available matrix: \n");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);
    
    // calculate the need matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    
    // check if the need matrix is less than the available matrix
    for (i = 0; i < n; i++)
    {
        flag = true;
        for (j = 0; j < m; j++)
        {
            if (need[i][j] > available[j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            // allocate the resources
            for (k = 0; k < m; k++)
                available[k] += allocation[i][k];
            
            // mark the process as finished
            finish[i] = 1;
            count++;
        }
    }
    
}

   