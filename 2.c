#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to create a new term
struct Term* createTerm(int coefficient, int exponent) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coefficient;
    newTerm->exponent = exponent;
    newTerm->next = NULL;
    return newTerm;
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* current = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        struct Term* newTerm = NULL;

        if (poly1->exponent > poly2->exponent) {
            newTerm = createTerm(poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            newTerm = createTerm(poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0) {
                newTerm = createTerm(sum, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (newTerm != NULL) {
            if (result == NULL) {
                result = newTerm;
                current = newTerm;
            } else {
                current->next = newTerm;
                current = current->next;
            }
        }
    }

    while (poly1 != NULL) {
        struct Term* newTerm = createTerm(poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;

        if (result == NULL) {
            result = newTerm;
            current = newTerm;
        } else {
            current->next = newTerm;
            current = current->next;
        }
    }

    while (poly2 != NULL) {
        struct Term* newTerm = createTerm(poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;

        if (result == NULL) {
            result = newTerm;
            current = newTerm;
        } else {
            current->next = newTerm;
            current = current->next;
        }
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Term* poly) {
    if (poly == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d ", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

int main() {
    // Create the first polynomial: 3x^2 + 2x + 1
    struct Term* poly1 = createTerm(3, 2);
    poly1->next = createTerm(2, 1);
    poly1->next->next = createTerm(1, 0);

    // Create the second polynomial: 2x^3 + 4x^2 + 1
    struct Term* poly2 = createTerm(2, 3);
    poly2->next = createTerm(4, 2);
    poly2->next->next = createTerm(1, 0);

    // Add the polynomials
    struct Term* result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Result: ");
    displayPolynomial(result);

    return 0;
}
