#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function to sort an array
void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to calculate the seek time using SCAN algorithm
void scanDiskScheduling(int requests[], int n, int head, int disk_size, int direction) {
    int seek_sequence[MAX];
    int index = 0;

    // Sort the requests array
    sort(requests, n);

    // Add the head to the sequence
    seek_sequence[index++] = head;

    if (direction == 1) {
        // Move right (to the end of the disk)
        for (int i = 0; i < n; i++) {
            if (requests[i] >= head) {
                seek_sequence[index++] = requests[i];
            }
        }
        // Add the end of the disk to the sequence
        if (head < disk_size - 1) {
            seek_sequence[index++] = disk_size - 1;
        }
        // Move left (back to the beginning of the disk)
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] < head) {
                seek_sequence[index++] = requests[i];
            }
        }
        // Add the beginning of the disk to the sequence
        if (head > 0) {
            seek_sequence[index++] = 0;
        }
    } else {
        // Move left (to the beginning of the disk)
        for (int i = n - 1; i >= 0; i--) {
            if (requests[i] <= head) {
                seek_sequence[index++] = requests[i];
            }
        }
        // Add the beginning of the disk to the sequence
        if (head > 0) {
            seek_sequence[index++] = 0;
        }
        // Move right (back to the end of the disk)
        for (int i = 0; i < n; i++) {
            if (requests[i] > head) {
                seek_sequence[index++] = requests[i];
            }
        }
        // Add the end of the disk to the sequence
        if (head < disk_size - 1) {
            seek_sequence[index++] = disk_size - 1;
        }
    }

    // Calculate total seek time
    int total_seek_time = 0;
    for (int i = 1; i < index; i++) {
        total_seek_time += abs(seek_sequence[i] - seek_sequence[i - 1]);
    }

    // Print seek sequence
    printf("Seek Sequence:\n");
    for (int i = 0; i < index; i++) {
        printf("%d ", seek_sequence[i]);
    }
    printf("\n");

    // Print total seek time
    printf("Total Seek Time: %d\n", total_seek_time);
}

int main() {
    int n, head, disk_size, direction;

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
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Input disk size
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    // Input direction (1 for right, 0 for left)
    printf("Enter the direction of head movement (1 for right, 0 for left): ");
    scanf("%d", &direction);

    // Perform SCAN disk scheduling
    scanDiskScheduling(requests, n, head, disk_size, direction);

    return 0;
}
