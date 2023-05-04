// Q02. Implement a program for Process Scheduling algorithm – SJF scheduling

// Assuming the arrival time of all the processes is zero

#include<stdio.h>
// #include<conio.h>

struct process
{
    int pid, arrival, burst, scheduling, completion, turnAround, waiting;
};

float avgTurnAround = 0, avgWaiting = 0;

void setATtoZero(struct process p[], int n)
{
    int i;
    // Setting the arrival time of all the processes to zero
    for(i = 0; i < n; i++)
    {
        p[i].arrival = 0;
    }
}

void sortProcessesBT(struct process p[], int n)
{
    int i, j;
    struct process tempProcess;
    // Sorting the processes according to their burst time
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(p[j].burst > p[j + 1].burst)
            {
                tempProcess = p[j];
                p[j] = p[j + 1];
                p[j + 1] = tempProcess;
            }
        }
    }
}

void sortProcessesPID(struct process p[], int n)
{
    int i, j;
    struct process tempProcess;
    // Sorting the processes according to their process id
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i].pid > p[j].pid)
            {
                tempProcess = p[i];
                p[i] = p[j];
                p[j] = tempProcess;
            }
        }
    }
}

void calculateCompletionTime(struct process p[], int n)
{
    int i;
    // Calculating the completion time of each process using scheduling time
    p[0].scheduling = p[0].arrival;
    p[0].completion = p[0].scheduling + p[0].burst;
    for(i = 1; i < n; i++)
    {
        p[i].scheduling = p[i - 1].completion;
        p[i].completion = p[i].scheduling + p[i].burst;
    }
}

void calculateTATWT(struct process p[], int n)
{
    int i;
    // Calculating the turn around time and waiting time of each process
    for(i = 0; i < n; i++)
    {
        p[i].turnAround = p[i].completion - p[i].arrival;
        avgTurnAround += p[i].turnAround;
        p[i].waiting = p[i].turnAround - p[i].burst;
        avgWaiting += p[i].waiting;
    }
}

void printProcesses(struct process p[], int n)
{
    int i;
    printf("\n\nPID\tArrival\tBurst\tScheduling\tCompletion\tTurn Around\tWaiting");
    for(i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d", 
        p[i].pid, p[i].arrival, p[i].burst, p[i].scheduling, 
        p[i].completion, p[i].turnAround, p[i].waiting);
    }
    printf("\n\nAverage Turn Around Time: %.2f", avgTurnAround / n);
    printf("\nAverage Waiting Time: %.2f", avgWaiting / n);
}

void printGanttChart(struct process p[], int n)
{
    int i, j;
    printf("\n\nGantt Chart:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d\t", p[i].pid);
    }
    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t", p[i].scheduling);
    }
    printf("%d\t", p[n - 1].completion);
}

int main()
{
    int n, i, j, temp;
    struct process p[10], tempProcess;
    // clrscr();

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        //printf("Enter the burst time of process %d: ", i + 1);
        scanf("%d", &p[i].burst);
        p[i].pid = i + 1;
    }

    setATtoZero(p, n);
    sortProcessesBT(p, n);
    calculateCompletionTime(p, n);
    calculateTATWT(p, n);
    printGanttChart(p, n);
    sortProcessesPID(p, n);
    printProcesses(p, n);

    // getch();
    return 0;
}

/*

5 1
2 2
3 3
2 4
4 1
3 3
*/