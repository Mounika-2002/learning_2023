//Dif between even & odd elements
#include <stdio.h>

int main() {
    int arr[] = {64, 84, 21, 36, 17, 90, 77, 10, 48, 55};
    int length = sizeof(arr) / sizeof(arr[0]);

    int sum_even = 0;
    int sum_odd = 0;

    for (int i = 0; i < length; i++) {
        if (arr[i] % 2 == 0) {
            sum_even += arr[i];
        } else {
            sum_odd += arr[i];
        }
    }

    int difference = sum_even - sum_odd;

    printf("Sum of even elements: %d\n", sum_even);
    printf("Sum of odd elements: %d\n", sum_odd);
    printf("Difference: %d\n", difference);

    return 0;
}
