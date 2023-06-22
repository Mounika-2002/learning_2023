#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(const struct Student* students, int numStudents, const char* name) {
    int found = 0;

    for (int i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            printf("\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Student with name '%s' not found.\n\n", name);
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Create an array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Assuming the array of structures is already initialized with student details

    // Clear the input buffer
    while (getchar() != '\n');

    // Input name to search
    char searchName[20];
    printf("Enter the name of the student to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';  // Removing the trailing newline character

    // Perform search operation based on name
    searchStudentByName(students, numStudents, searchName);

    // Free the memory allocated for the array of structures
    free(students);

    return 0;
}
