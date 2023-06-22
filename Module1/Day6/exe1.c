#include <stdio.h>

// Define the structure for the box
struct Box {
    double length;
    double width;
    double height;
};

// Function to calculate the volume of the box
double calculateVolume(struct Box* boxPtr) {
    return boxPtr->length * boxPtr->width * boxPtr->height;
}

// Function to calculate the total surface area of the box
double calculateSurfaceArea(struct Box* boxPtr) {
    double length = boxPtr->length;
    double width = boxPtr->width;
    double height = boxPtr->height;
    return 2 * (length * width + length * height + width * height);
}

int main() {
    // Create a box object
    struct Box myBox;
    myBox.length = 7.0;
    myBox.width = 5.0;
    myBox.height = 4.0;

    // Create a pointer to the box object
    struct Box* boxPtr = &myBox;

    // Calculate the volume and surface area using the structure pointer
    double volume = calculateVolume(boxPtr);
    double surfaceArea = calculateSurfaceArea(boxPtr);

    // Print the results
    printf("Volume of the box: %.2f\n", volume);
    printf("Total surface area of the box: %.2f\n", surfaceArea);

    return 0;
}
