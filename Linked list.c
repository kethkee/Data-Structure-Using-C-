#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

typedef struct node NODE;
NODE *header = NULL, *newptr = NULL, *ptr, *ptr1;

void traverse();
void insertfront();
void insertend();
void insertany();
void deletefront();
void deleteend();
void deleteany();
void display();  // Function prototype for displaying the list

void main() {
    int no;
    char c;
    header = (NODE*)malloc(sizeof(NODE));  // Initialize header node
    header->link = NULL;

    printf("\n\tPROGRAM TO PERFORM OPERATIONS ON SINGLE LINKED LIST");
    printf("\n\t.......................................................");

    do {
        printf("\n\t\t\t\tMENU\n\n");
        printf("\t\t1.TRAVERSE\n\t\t2.INSERT AT FRONT\n\t\t3.INSERT AT END\n\t\t4.INSERT AT ANY POSITION\n\t\t5.DELETE FROM FRONT\n\t\t6.DELETE FROM END\n\t\t7.DELETE FROM ANY POSITION\n\t\t8.DISPLAY LIST\n\t\t9.EXIT\n\t\tEnter your choice: ");
        scanf("%d", &no);
        if (no == 9)
            break;
        else {
            switch(no) {
                case 1: traverse(); break;
                case 2: insertfront(); break;
                case 3: insertend(); break;
                case 4: insertany(); break;
                case 5: deletefront(); break;
                case 6: deleteend(); break;
                case 7: deleteany(); break;
                case 8: display(); break;  // Call display function here
                default: printf("\t\tINVALID ENTRY\n"); break;
            }

            printf("\t\tDo you want to continue (y/n): ");
            scanf(" %c", &c);
        }
    } while(c == 'y' || c == 'Y');
}

void insertfront() {
    newptr = (NODE*)malloc(sizeof(NODE));
    if (newptr == NULL) {
        printf("\t\tInsufficient memory\n");
        return;
    }
    printf("\t\tEnter the element: ");
    scanf("%d", &newptr->data);
    newptr->link = NULL;

    newptr->link = header->link;  // Point new node to the first node
    header->link = newptr;  // Update header to point to the new first node
}

void insertend() {
    newptr = (NODE*)malloc(sizeof(NODE));
    if (newptr == NULL) {
        printf("\t\tInsufficient memory\n");
        return;
    }
    printf("\t\tEnter the element: ");
    scanf("%d", &newptr->data);
    newptr->link = NULL;

    ptr = header;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newptr;  // Insert new node at the end
}

void insertany() {
    int key;
    newptr = (NODE*)malloc(sizeof(NODE));
    if (newptr == NULL) {
        printf("\t\tInsufficient memory\n");
        return;
    }
    printf("\t\tEnter the key after which to insert: ");
    scanf("%d", &key);
    printf("\t\tEnter the element: ");
    scanf("%d", &newptr->data);

    ptr = header->link;
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->link;
    }

    if (ptr == NULL)
        printf("\t\tKey not found\n");
    else {
        newptr->link = ptr->link;  // Insert new node after the key node
        ptr->link = newptr;
    }
}

void deletefront() {
    if (header->link == NULL) {
        printf("\t\tEmpty list\n");
        return;
    }

    ptr = header->link;
    header->link = ptr->link;  // Remove the first node
    printf("\t\tDeleted element is %d\n", ptr->data);
    free(ptr);  // Free the deleted node
}

void deleteend() {
    if (header->link == NULL) {
        printf("\t\tEmpty list\n");
        return;
    }

    ptr = header;
    ptr1 = header->link;
    if (ptr1->link == NULL) {  // Only one node present
        header->link = NULL;
        printf("\t\tDeleted element is %d\n", ptr1->data);
        free(ptr1);
        return;
    }

    while (ptr1->link != NULL) {
        ptr = ptr1;
        ptr1 = ptr1->link;
    }
    ptr->link = NULL;  // Remove the last node
    printf("\t\tDeleted element is %d\n", ptr1->data);
    free(ptr1);
}

void deleteany() {
    int key;
    if (header->link == NULL) {
        printf("\t\tEmpty list\n");
        return;
    }

    printf("\t\tEnter the key to delete: ");
    scanf("%d", &key);

    ptr = header;
    ptr1 = header->link;

    while (ptr1 != NULL && ptr1->data != key) {
        ptr = ptr1;
        ptr1 = ptr1->link;
    }

    if (ptr1 == NULL)
        printf("\t\tKey not found\n");
    else {
        ptr->link = ptr1->link;  // Remove the node with the key
        printf("\t\tDeleted element is %d\n", ptr1->data);
        free(ptr1);
    }
}

void traverse() {
    if (header->link == NULL) {
        printf("\t\tList is empty\n");
        return;
    }

    printf("\t\tElements are:\n\t\t");
    ptr = header->link;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void display() {  // New function to display the linked list
    if (header->link == NULL) {
        printf("\t\tList is empty\n");
        return;
    }

    printf("\t\tDisplaying the linked list:\n\t\t");
    ptr = header->link;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}
