#include <stdio.h>
#include <stdlib.h>
struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compareDescending(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    // Compare marks in descending order
    if (studentA->marks > studentB->marks) {
        return -1;
    } else if (studentA->marks < studentB->marks) {
        return 1;
    } else {
        return 0;
    }
}

void sortStudentsDescending(struct Student* students, int numStudents) {
    qsort(students, numStudents, sizeof(struct Student), compareDescending);
}

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

    // Sort the array of structures in descending order based on marks
    sortStudentsDescending(students, numStudents);

    // Display the sorted student details
    printf("Sorted Student Details (Descending Order):\n");
    displayStudents(students, numStudents);

    // Free the memory allocated for the array of structures
    free(students);

    return 0;
}
