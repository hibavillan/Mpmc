#include <stdio.h>
#include <stdlib.h>

// Function to calculate the total seek time
int calculateSeekTime(int arr[], int n) {
    int seek_time = 0;
    
    for (int i = 1; i < n; i++) {
        seek_time += abs(arr[i] - arr[i - 1]);
    }
    
    return seek_time;
}

int main() {
    int n;

    // Input number of disk requests
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    int requests[n];
    
    // Input disk requests
    printf("Enter the disk requests:\n");
    for (int i = 0; i < n; i++) {
        printf("Request %d: ", i + 1);
        scanf("%d", &requests[i]);
    }
    
    // Input the initial head position
    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    
    // Insert the initial head position at the start of requests array
    int seek_sequence[n + 1];
    seek_sequence[0] = head;
    
    // Copy requests to seek_sequence
    for (int i = 0; i < n; i++) {
        seek_sequence[i + 1] = requests[i];
    }
    
    // Calculate seek time
    int total_seek_time = calculateSeekTime(seek_sequence, n + 1);
    
    // Print seek sequence
    printf("Seek Sequence:\n");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");
    
    // Print the total seek time
    printf("Total Seek Time: %d\n", total_seek_time);

    return 0;
}
