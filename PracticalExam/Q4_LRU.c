// Q04. Implement a program for Page Replacement policy :LRU

#include <stdio.h>
// #include <conio.h>

int main() {
    int i, j, n, pages[50], frame[10], m, k, found, fault, hit, time[10], min, replace;
    fault = 0;
    hit = 0;

    //clrscr();

    printf("\nEnter the number of pages: ");
    scanf("%d", &n);

    printf("Enter the page number: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &m);

    // Initialize the frames and time array to -1 to indicate they are empty
    for (i = 0; i < m; i++) {
        frame[i] = -1;
        time[i] = -1;
    }

    j = 0;
    printf("\nREF string\t page frames\n");
    for (i = 1; i <= n; i++) 
    {
        printf("%d\t\t", pages[i]);
        found = 0;
        // Check if the page is already in a frame
        for (k = 0; k < m; k++)
            if (frame[k] == pages[i])
            {
                found = 1;
                hit++;
                time[k] = i; // Update the time array with the current time
                break;
            }

        if (found == 0) 
        {
            min = n+1; // Initialize to the maximum possible time
            replace = -1; // Find the least recently used page in the frame
            for (k = 0; k < m; k++) {
                if (time[k] < min) {
                    min = time[k];
                    replace = k;
                }
            }
            frame[replace] = pages[i];
            time[replace] = i;
            fault++;
        }
        for (k = 0; k < m; k++)
        printf("%d\t", frame[k]);
        printf("\n");
    }
    printf("Page Fault is %d", fault);
    printf("\nPage Hit is %d", hit);

    // getch();
    return 0;
}

/*
Output:
Enter the number of pages: 5
Enter the page number: 1 2 3 2 5
Enter the number of frames: 3

*/