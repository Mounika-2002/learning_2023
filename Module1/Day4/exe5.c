//Diff between even & odd indexed elements
#include <stdio.h>

int main() {
    int arr[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int length = sizeof(arr) / sizeof(arr[0]);

    int sum_even_indexed = 0;
    int sum_odd_indexed = 0;

    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            sum_even_indexed += arr[i];
        } else {
            sum_odd_indexed += arr[i];
        }
    }

    int difference = sum_even_indexed - sum_odd_indexed;

    printf("Sum of even indexed elements: %d\n", sum_even_indexed);
    printf("Sum of odd indexed elements: %d\n", sum_odd_indexed);
    printf("Difference: %d\n", difference);

    return 0;
}
