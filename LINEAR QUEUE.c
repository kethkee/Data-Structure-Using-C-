#include<stdio.h>
int en_queue(int queue[], int rear, int n) {
    if (rear > n - 1) {
        printf("Queue overflow\n");
    } else {
        int item;
        rear++;
        printf("Enter item to be inserted: ");
        scanf("%d", &item);
        queue[rear] = item;
    }
    return rear;
}

int de_queue(int queue[], int front, int rear) {
    if (front > rear) {
        printf("Queue underflow\n");
    } else {
        printf("Deleted item is: %d\n", queue[front]);
        front++;
    }
    return front;
}

void display(int queue[], int front, int rear) {
    if (front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("The queue is:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, option;
    int front = 0, rear = -1;
    char ch = 'y';

    printf("Enter the size of the queue: ");
    scanf("%d", &n);

    int queue[n];

    do {
        printf("\n*QUEUE OPERATIONS*");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                rear = en_queue(queue, rear, n);
                break;
            case 2:
                front = de_queue(queue, front, rear);
                break;
            case 3:
                display(queue, front, rear);
                break;
            default:
                printf("\nInvalid option\n");
        }

        printf("\nDo you want to continue? (Y/N): ");
        getchar();
        scanf("%c", &ch);

    } while (ch == 'Y' || ch == 'y');

    printf("\nExiting\n");
    return 0;
}
