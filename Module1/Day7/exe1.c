#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseInputString(const char* input, struct Student* students, int numStudents) {
    const char* delimiter = " ";
    char* token;

    // Iterate through the input string and initialize the array of structures
    for (int i = 0; i < numStudents; i++) {
        // Parsing rollno
        token = strtok((char*)input, delimiter);
        students[i].rollno = atoi(token);

        // Parsing name
        token = strtok(NULL, delimiter);
        strncpy(students[i].name, token, sizeof(students[i].name));

        // Parsing marks
        token = strtok(NULL, delimiter);
        students[i].marks = atof(token);

        input = NULL;  // Set input to NULL to continue parsing the same string
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Create an array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Clear the input buffer
    while (getchar() != '\n');

    // Input string
    char inputString[100];
    printf("Enter the student details (rollno name marks): ");
    fgets(inputString, sizeof(inputString), stdin);

    // Removing the trailing newline character from the input string
    inputString[strcspn(inputString, "\n")] = '\0';

    // Parse the input string and initialize the array of structures
    parseInputString(inputString, students, numStudents);

    // Print the student details
    printf("Student Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    // Free the memory allocated for the array of structures
    free(students);

    return 0;
}
