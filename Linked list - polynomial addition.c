#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node {
    int coeff; // Coefficient of the polynomial
    int expo;  // Exponent (power) of the polynomial
    struct Node* next; // Pointer to the next node
};

// Function to create a new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = c;
    newNode->expo = e;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the linked list
void appendNode(struct Node** head, int coeff, int expo) {
    struct Node* newNode = createNode(coeff, expo);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the polynomial
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo > poly2->expo) {
            appendNode(&result, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            appendNode(&result, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            appendNode(&result, sumCoeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    // Append remaining terms of poly1
    while (poly1 != NULL) {
        appendNode(&result, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    // Append remaining terms of poly2
    while (poly2 != NULL) {
        appendNode(&result, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return result;
}

// Main function to handle input/output
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;
    int n, coeff, expo;

    // Input for the first polynomial
    printf("Enter number of terms for the first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        appendNode(&poly1, coeff, expo);
    }

    // Input for the second polynomial
    printf("Enter number of terms for the second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &expo);
        appendNode(&poly2, coeff, expo);
    }

    // Display the two polynomials
    printf("First polynomial: ");
    display(poly1);
    printf("Second polynomial: ");
    display(poly2);

    // Add the two polynomials
    result = addPolynomials(poly1, poly2);

    // Display the result
    printf("Resultant polynomial after addition: ");
    display(result);

    return 0;
}
