#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 4096
void convertToUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void convertToLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void convertToSentenceCase(char *str) {
    int capitalizeNext = 1;
    while (*str) {
        if (capitalizeNext && isalpha((unsigned char)*str)) {
            *str = toupper((unsigned char)*str);
            capitalizeNext = 0;
        }
        else {
            *str = tolower((unsigned char)*str);
            if (*str == '.' || *str == '!' || *str == '?')
                capitalizeNext = 1;
        }
        str++;
    }
}

void copyFile(FILE *sourceFile, FILE *targetFile, int convertCase) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) {
        if (convertCase == 1)
            convertToUpperCase(buffer);
        else if (convertCase == 2)
            convertToLowerCase(buffer);
        else if (convertCase == 3)
            convertToSentenceCase(buffer);

        fwrite(buffer, 1, bytesRead, targetFile);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [-u | -l | -s] source_file target_file\n", argv[0]);
        return 1;
    }

    char *option = "";
    char *sourcePath = "";
    char *targetPath = "";

    if (argc == 4)
        option = argv[1];
    sourcePath = argv[argc - 2];
    targetPath = argv[argc - 1];

    FILE *sourceFile = fopen(sourcePath, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    FILE *targetFile = fopen(targetPath, "w");
    if (targetFile == NULL) {
        printf("Unable to create the target file.\n");
        fclose(sourceFile);
        return 1;
    }

    int convertCase = 0; // 0 = No conversion, 1 = Upper case, 2 = Lower case, 3 = Sentence case

    if (strcmp(option, "-u") == 0)
        convertCase = 1;
    else if (strcmp(option, "-l") == 0)
        convertCase = 2;
    else if (strcmp(option, "-s") == 0)
        convertCase = 3;

    copyFile(sourceFile, targetFile, convertCase);

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(targetFile);

    return 0;
}
