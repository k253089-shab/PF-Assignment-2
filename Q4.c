#include <stdio.h>
						
int push(int stack[], int top, int maxSize);
int pop(int stack[], int top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int maxSize;
    int stack[100];   
    int top = -1;
    int choice;
    int running = 1;

    printf("Enter the maximum size of the stack (up to 100): ");
    scanf("%d", &maxSize);

    while (running) {
        printf("\n----- STACK MENU -----\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                top = push(stack, top, maxSize);
                break;
            case 2:
                top = pop(stack, top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Program terminated.\n");
                printf("---------------------\n");
                running = 0;
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                 printf("---------------------------------\n");
        }
    }

    return 0;
}
							
int push(int stack[], int top, int maxSize) {
    int value;
    if (top == maxSize - 1) {
        printf("Stack Overflow! Cannot push more elements.\n");
         printf("--------------------------------------------\n");
    } else {
        printf("Enter value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("%d pushed into stack.\n", value);
         printf("------------------------------\n");
    }
    return top;
}
								
int pop(int stack[], int top) {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
         printf("--------------------------------\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top--;
    }
    return top;
}
								
void peek(int stack[], int top) {
    if (top == -1) {
        printf("Stack is empty.\n");
         printf("---------------------\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
         printf("---------------------\n");
    }
}
												
void display(int stack[], int top) {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
         printf("---------------------\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

