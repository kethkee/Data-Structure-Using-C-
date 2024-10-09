#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *header, *newptr, *ptr1, *ptr2, *ptr;

void insertfront();
void insertend();
void insertany();
void deletefront();
void deleteend();
void deleteany();
void display();
void traverse();  // Traversal function declaration

void main() {
    header = NULL;  
    char ch = 'Y';
    int op;

    while (ch == 'y' || ch == 'Y') {
        printf("1.INSERT AT FRONT\n2.INSERT AT END\n3.INSERT AT ANY POSITION\n4.DELETE FROM FRONT\n5.DELETE FROM END\n6.DELETE FROM ANY POSITION\n7.DISPLAY\n8.TRAVERSE\n9.EXIT\n");
        printf("Enter which operation to perform?: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                insertfront();
                break;
            case 2:
                insertend();
                break;
            case 3:
                insertany();
                break;
            case 4:
                deletefront();
                break;
            case 5:
                deleteend();
                break;
            case 6:
                deleteany();
                break;
            case 7:
                display();
                break;
            case 8:
                traverse();  // Call to the traversal function
                break;
            case 9:   
                printf("Exiting program...\n");
                exit(0);  
            default:
                printf("Invalid option!\n");
                break;
        }

        printf("Do you want to continue? (Y/N): ");
        getchar();  
        scanf("%c", &ch);
    }
}

void insertfront() {
    newptr = (struct node *)malloc(sizeof(struct node));

    printf("Enter data of the node: ");
    scanf("%d", &newptr->data);
    newptr->link = header;
    header = newptr;
}

void insertend() {
    newptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data of the node: ");
    scanf("%d", &newptr->data);
    newptr->link = NULL;

    if (header == NULL) {
        header = newptr;  
    } else {
        ptr = header;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = newptr;
    }
}

void insertany() {
    int key;
    newptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter key value: ");
    scanf("%d", &key);

    ptr1 = header;
    while (ptr1 != NULL && ptr1->data != key) {
        ptr1 = ptr1->link;
    }

    if (ptr1 == NULL) {
        printf("Key not found!\n");
        return;
    }

    printf("Enter data of the node: ");
    scanf("%d", &newptr->data);
    newptr->link = ptr1->link;
    ptr1->link = newptr;
}

void deletefront() {
    if (header == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    ptr = header;
    printf("%d deleted\n", ptr->data);
    header = header->link;
    free(ptr);
}

void deleteend() {
    if (header == NULL) {
        printf("Linked list is empty!\n");
        return;
    }

    ptr1 = header;
    if (ptr1->link == NULL) {
        printf("%d deleted\n", ptr1->data);
        free(ptr1);
        header = NULL;  
        return;
    }

    ptr2 = ptr1->link;
    while (ptr2->link != NULL) {
        ptr1 = ptr2;
        ptr2 = ptr2->link;
    }

    printf("%d deleted\n", ptr2->data);
    ptr1->link = NULL;
    free(ptr2);
}

void deleteany() {
    int key;
    printf("Enter key value: ");
    scanf("%d", &key);

    ptr1 = header;
    if (ptr1 == NULL) {
        printf("Empty linked list!\n");
        return;
    }

    ptr2 = ptr1->link;
    if (ptr1->data == key) {  
        header = ptr1->link;
        free(ptr1);
        printf("Deleted node with key %d\n", key);
        return;
    }

    while (ptr2 != NULL && ptr2->data != key) {
        ptr1 = ptr2;
        ptr2 = ptr2->link;
    }

    if (ptr2 == NULL) {
        printf("Key not found!\n");
    } else {
        ptr1->link = ptr2->link;
        printf("%d deleted\n", ptr2->data);
        free(ptr2);
    }
}

void display() {
    if (header == NULL) {
        printf("\t\tList is empty\n");
        return;
    }

    printf("\t\tDisplaying the linked list:\n\t\t");
    ptr = header;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

// Traversal function
void traverse() {
    if (header == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Traversing the linked list:\n");
    ptr = header;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL\n");
}
