//Convert String as Integer
#include <stdio.h>

int stringToInteger(char* str) {
    int res = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        int ival = str[i] - '0';
        res = res * 10 + ival;
    }
    return res;
}

int main() {
    char str[] = "5278";
    printf("Input String: %s\n", str);

    int value = stringToInteger(str);

    printf("Integer value: %d\n", value);

    return 0;
}
