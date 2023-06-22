#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    double real;
    double imag;
};

// Function to read a complex number from the user
void readComplex(struct Complex* complex) {
    printf("Enter the real part: ");
    scanf("%lf", &(complex->real));
    printf("Enter the imaginary part: ");
    scanf("%lf", &(complex->imag));
}

// Function to write a complex number to the console
void writeComplex(struct Complex* complex) {
    printf("Complex number: %.2f + %.2fi\n", complex->real, complex->imag);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex* complex1, struct Complex* complex2) {
    struct Complex result;
    result.real = complex1->real + complex2->real;
    result.imag = complex1->imag + complex2->imag;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex* complex1, struct Complex* complex2) {
    struct Complex result;
    result.real = (complex1->real * complex2->real) - (complex1->imag * complex2->imag);
    result.imag = (complex1->real * complex2->imag) + (complex1->imag * complex2->real);
    return result;
}

int main() {
    // Create two complex numbers
    struct Complex complex1, complex2;

    // Read the first complex number
    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    // Read the second complex number
    printf("Enter the second complex number:\n");
    readComplex(&complex2);

    // Write the complex numbers
    printf("\n");
    printf("First complex number:\n");
    writeComplex(&complex1);
    printf("Second complex number:\n");
    writeComplex(&complex2);
    printf("\n");

    // Perform addition of complex numbers
    struct Complex sum = addComplex(&complex1, &complex2);
    printf("Addition of complex numbers:\n");
    writeComplex(&sum);
    printf("\n");

    // Perform multiplication of complex numbers
    struct Complex product = multiplyComplex(&complex1, &complex2);
    printf("Multiplication of complex numbers:\n");
    writeComplex(&product);
    printf("\n");

    return 0;
}
