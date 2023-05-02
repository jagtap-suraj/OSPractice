// Q08. Implement a program for disk scheduling algorithm – LOOK

#include <stdio.h>
#include <stdlib.h>
// #include<conio.h>

int main() {
    int n, i, j, head, current, seek_time = 0, direction, temp, index;
    int requests[100];
    int visited[100] = {0};
    // clrscr();

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter the initial position of the head: ");
    scanf("%d", &head);

    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &direction);

    // sort the requests in ascending order
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (requests[j] > requests[j + 1]) 
            {
                temp = requests[j];
                requests[j] = requests[j + 1];
                requests[j + 1] = temp;
            }
        }
    }

    // find the index of the head in the sorted array
    if (direction == 0) 
    {
        for (i = 0; i < n; i++) 
        {
            if (requests[i] > head) 
            {
                index = i - 1;
                break;
            }
        }
    } 
    else 
    {
        for (i = n - 1; i >= 0; i--) 
        {
            if (requests[i] < head) 
            {
                index = i + 1;
                break;
            }
        }
    }

    // iterate over the requests in the given direction
    for (i = index; i >= 0 && i < n; i += direction * 2 - 1) 
    {
        current = requests[i];
        seek_time += abs(head - current);
        head = current;
        visited[i] = 1; // mark the request as visited
        printf("%d -> ", head);
    }

    // iterate over the requests in the opposite direction
    for (i = index - direction; i >= 0 && i < n; i -= direction * 2 - 1) 
    {
        if (visited[i]) {
            continue; // skip the request if it has already been processed
        }
        current = requests[i];
        seek_time += abs(head - current);
        head = current;
        visited[i] = 1; // mark the request as visited
        printf("%d -> ", head);
    }

    printf("\nTotal seek time: %d\n", seek_time);

    // getch();
    return 0;
}

/*Output:
Enter the number of requests: 8
Enter the initial position of the head: 50
Enter the requests: 176 79 34 60 92 11 41 114
50 -> 176 -> 79 -> 34 -> 60 -> 92 -> 11 -> 41 -> 114 -> 
Total seek time: 510

176 79 34 60 92 11 41 114
*/

