#include <stdio.h>

int findSmallestDigit(int num) {
    int smallest = 9;  // Initialize the smallest digit to 9 (maximum digit value)
    
    while (num > 0) {
        int digit = num % 10;  // Extract the last digit
        
        if (digit < smallest)
            smallest = digit;
        
        num /= 10;  // Remove the last digit
    }
    
    return smallest;
}

int findLargestDigit(int num) {
    int largest = 0;  // Initialize the largest digit to 0 (minimum digit value)
    
    while (num > 0) {
        int digit = num % 10;  // Extract the last digit
        
        if (digit > largest)
            largest = digit;
        
        num /= 10;  // Remove the last digit
    }
    
    return largest;
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    if (n < 1) {
        printf("Not Valid\n");
        return 0;
    }
    
    int num, smallest, largest;
    
    printf("Enter %d numbers:\n", n);
    scanf("%d", &num);
    
    smallest = findSmallestDigit(num);
    largest = findLargestDigit(num);
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &num);
        
        int smallestDigit = findSmallestDigit(num);
        int largestDigit = findLargestDigit(num);
        
        if (smallestDigit < smallest)
            smallest = smallestDigit;
        
        if (largestDigit > largest)
            largest = largestDigit;
    }
    
    printf("Smallest digit: %d\n", smallest);
    printf("Largest digit: %d\n", largest);
    
    return 0;
}
