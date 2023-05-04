#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int bt[n], ct[n], wt[n], tat[n];
    float awt = 0, atat = 0;

    printf("Enter the burst time of each process:\n");
    for(int i=0;i<n;i++) {
        scanf("%d",&bt[i]);
    }

    //Shortest Job First
    int min = 0;
    for(int i=0;i<n;i++) {
        min = i;
        for(int j=i+1;j<n;j++) {
            if(bt[j] < bt[min]) {
                min = j;
            }
        }
        int temp = bt[i];
        bt[i] = bt[min];
        bt[min] = temp;
    }

    //Completion Time
    for(int i=0;i<n;i++) {
        if(i == 0) {
            ct[i] = bt[i];
        }
        else {
            ct[i] = ct[i-1] + bt[i];
        }
    }

    //Turn Around Time
    for(int i=0;i<n;i++) {
        tat[i] = ct[i];
    }

    //Waiting Time
    for(int i=0;i<n;i++) {
        wt[i] = tat[i] - bt[i];
    }

    //Average Waiting Time
    for(int i=0;i<n;i++) {
        awt += wt[i];
    }
    awt /= n;

    //Average Turn Around Time
    for(int i=0;i<n;i++) {
        atat += tat[i];
    }
    atat /= n;

    printf("Process\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n",i+1,bt[i],ct[i],tat[i],wt[i]);
    }
    printf("Average Waiting Time: %f\n",awt);
    printf("Average Turn Around Time: %f\n",atat);

    return 0;
}