#include <stdio.h>
#include <stdlib.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeStudents(struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        students[i].rollno = 0;
        students[i].name[0] = '\0';
        students[i].marks = 0.0;
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Create an array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Initialize all members in the array of structures
    initializeStudents(students, numStudents);

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
