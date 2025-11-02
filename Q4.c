#include <stdio.h>

void Push(int stack[],int *count);
void Pop(int stack[],int *count);
void Peek(int stack[],int *count);
void Display(int stack[],int *count);

int main(){
    int stack[10];
    int count = 0;
    int Flag = 1;
    int choice = 0;
    printf("\nWelcome to stack management system.");
    while(Flag == 1){
        printf("\nEnter 1 to Push");
        printf("\nEnter 2 to Pop");
        printf("\nEnter 3 to Peek");
        printf("\nEnter 4 to Display: ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: Push(stack,&count);
                    break;
            case 2: Pop(stack,&count);
                    break;
            case 3: Peek(stack,&count);
                    break;
            case 4: Display(stack,&count);
                    break;
            default: printf("\nInvalid choice");
                    break;
        }
        printf("\nIf you want to continue Enter 1: ");
        scanf("%d",&Flag);
    }
    return 0;
}

void Push(int stack[],int *count){
    int num;
    printf("\nEnter the number you ant to add: ");
    scanf("%d", &num);
    if (*count == 10){
        printf("\nStack is full");
    }
    else{
        stack[*count] = num;
        (*count)++;
        printf("\nItem sucessfully added.");
    }
}

void Pop(int stack[],int *count){
    if (*count == 0){
        printf("\nStack already empty");
    }
    else{
        (*count)--; // 
    printf("\nItem %d removed successfully.", stack[*count]);
    }    
}

void Peek(int stack[],int *count){
    if (*count == 0) {
        printf("\nStack is empty!");
    } else {
        printf("\nTop element: %d", stack[*count - 1]);
    }
}

void Display(int stack[],int *count){
    int i;
    if (*count == 0) {
    printf("\nStack is empty!");
    return;
}
    for(i = 0;i<*count;i++){
        printf("\n%d", stack[i]);
    }
}
