#include <stdio.h>
// #include <conio.h>

int main() {
    int i, j, n, pages[50], frame[20], m, k, found, fault, hit;
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

    // Initialize the frames to -1 to indicate they are empty
    for (i = 0; i < m; i++)
        frame[i] = -1;

    j = 0;
    printf("\nREF string\t page frames\n");
    for (i = 1; i <= n; i++) 
    {
        printf("%d\t\t", pages[i]); //**
        found = 0;
        // Check if the page is already in a frame
        for (k = 0; k < m; k++)
            if (frame[k] == pages[i])
            {
                found = 1;
                hit++;
                break;
            }

        if (found == 0) 
        {
            frame[j] = pages[i];
            j = (j + 1) % m; // Move to the next frame (using circular buffer) **
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
Enter the number of pages: 5
Enter the page number: 1 2 3 2 5
Enter the number of frames: 3

REF string      page frames
1               1       -1      -1
2               1       2       -1
3               1       2       3
2               1       2       3
5               5       2       3
Page Fault is 4

*/