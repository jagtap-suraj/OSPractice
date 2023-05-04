//Frist Come First Serve Scheduling Algorithm

#include<stdio.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], ct[n], wt[n], tat[n];
    float awt = 0, atat = 0;

    printf("Enter the arrival time and burst time of each process:\n");
    for(int i=0;i<n;i++) {
        scanf("%d %d",&at[i], &bt[i]);
    }

    //Sort the processes according to their arrival time
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(at[j] > at[j+1]) {
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
            }
        }
    }

    wt[0] = 0;
    ct[0] = bt[0];
    tat[0] = ct[0] - at[0];
    for(int i=1;i<n;i++) {
        ct[i] = ct[i-1] + bt[i];
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0;i<n;i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],ct[i],wt[i],tat[i]);
        awt += wt[i];
        atat += tat[i];
    }
    
    return 0;
}
