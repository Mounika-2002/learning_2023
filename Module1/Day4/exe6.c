//Toggle Case
#include <stdio.h>
#include <ctype.h>

void toggleCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
    }
}

int main() {
    char str[] = "Hello World";
    printf("Input String: %s\n", str);

    toggleCase(str);

    printf("Output String: %s\n", str);

    return 0;
}
