#include <stdio.h>
#include <string.h>

// Structure to represent a car
struct Car {
    char make[50];
    char model[50];
    int year;
};

// Function to swap the fields of two Car structures using pointers
void swapCars(struct Car* car1, struct Car* car2) {
    // Swap the make
    char tempMake[50];
    strcpy(tempMake, car1->make);
    strcpy(car1->make, car2->make);
    strcpy(car2->make, tempMake);

    // Swap the model
    char tempModel[50];
    strcpy(tempModel, car1->model);
    strcpy(car1->model, car2->model);
    strcpy(car2->model, tempModel);

    // Swap the year
    int tempYear = car1->year;
    car1->year = car2->year;
    car2->year = tempYear;
}

int main() {
    // Create two Car structures
    struct Car car1, car2;

    // Read the make, model, and year for the first car
    printf("Enter the make of the first car: ");
    fgets(car1.make, 50, stdin);
    printf("Enter the model of the first car: ");
    fgets(car1.model, 50, stdin);
    printf("Enter the year of the first car: ");
    scanf("%d", &(car1.year));

    // Clear the input buffer
    getchar();

    // Read the make, model, and year for the second car
    printf("Enter the make of the second car: ");
    fgets(car2.make, 50, stdin);
    printf("Enter the model of the second car: ");
    fgets(car2.model, 50, stdin);
    printf("Enter the year of the second car: ");
    scanf("%d", &(car2.year));

    // Print the original cars
    printf("\nOriginal Cars:\n");
    printf("Car 1: Make - %sModel - %sYear - %d\n", car1.make, car1.model, car1.year);
    printf("Car 2: Make - %sModel - %sYear - %d\n", car2.make, car2.model, car2.year);

    // Swap the fields of the two cars
    swapCars(&car1, &car2);

    // Print the swapped cars
    printf("\nSwapped Cars:\n");
    printf("Car 1: Make - %sModel - %sYear - %d\n", car1.make, car1.model, car1.year);
    printf("Car 2: Make - %sModel - %sYear - %d\n", car2.make, car2.model, car2.year);

    return 0;
}
