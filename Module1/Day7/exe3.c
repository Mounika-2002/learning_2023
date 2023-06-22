#include <stdio.h>
#include <stdlib.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayStudents(const struct Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i+1);
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Create an array of structures
    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));

    // Assuming the array of structures is already initialized with student details

    // Display all members in the array of structures
    displayStudents(students, numStudents);

    // Free the memory allocated for the array of structures
    free(students);

    return 0;
}
