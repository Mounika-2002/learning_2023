//Reverse The Array
#include <stdio.h>

void reverseArray(int arr[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move start and end indices
        start++;
        end--;
    }
}

int main() {
    int arr[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56, 56, 84, 20, 36, 12, 90, 72, 10, 45, 64, 56, 45, 20, 36, 12, 90, 72, 10, 84, 
    64, 56, 45, 10, 36,12, 90, 72, 20, 84, 64, 56, 45, 10, 72, 12, 90, 36, 20, 84, 64, 56, 45, 10, 72, 90, 12, 36, 20, 84, 64};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    reverseArray(arr, length);

    printf("\nReversed Array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
