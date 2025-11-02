#include <stdio.h>
#include <string.h>

void addBook(int isbn[100], char titles[100][50], float prices[100], int quantities[100], int *count);
void processSale(int isbn[100], int quantities[100], int count);
void lowStockReport(int isbn[100], char titles[100][50], float prices[100], int quantities[100], int count);
    
int main()
{
        int isbn[100], quantities[100], count=0;
        char titles[100][50];
        float prices[100];
        int choice;
        
        do{
            printf("\n--- Liberty Books Inventory System ---\n");
            printf("1. Add New Book\n");
            printf("2. Process a Sale\n");
            printf("3. Generate Low-Stock Report\n");
            printf("4. Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
        
            switch(choice){
                case 1: 
                    addBook(isbn, titles, prices, quantities, &count);
                    break;
                case 2:
                    processSale(isbn, quantities, count);
                    break;
                case 3:
                    lowStockReport(isbn, titles, prices, quantities, count);
                    break;
                case 4:
                    printf("Exiting program...\n");
                    break;
                default:
                    printf("Invlaid choice");
            }
        }
        while(choice!=4);
        
    return 0;
}

    void addBook(int isbn[100], char titles[100][50], float prices[100], int quantities[100], int *count){
        printf("Enter ISBN: ");
        scanf("%d", &isbn[*count]);
        
        getchar();
        printf("Enter title: ");
        fgets(titles[*count], sizeof(titles[*count]), stdin);
        titles[*count][strcspn(titles[*count], "\n")] = '\0';
        
        printf("Enter prices: ");
        scanf("%f", &prices[*count]);
        
        printf("Enter quantity: ");
        scanf("%d", &quantities[*count]);
    
        (*count)++;
        printf("Book added successfully!\n");
    }   
    
void processSale(int isbn[100], int quantities[100], int count){
    int targetISBN, sold, found=0;
    printf("Enter ISBN: ");
    scanf("%d", &targetISBN);
    
for (int i = 0; i < count; i++) {
        if (isbn[i] == targetISBN) {
            printf("Enter number of copies sold: ");
            scanf("%d", &sold);

            if (sold > quantities[i]) {
                printf("Not enough stock! Only %d available.\n", quantities[i]);
            } else {
                quantities[i] -= sold;
                printf("Sale processed. Remaining stock: %d\n", quantities[i]);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Book not found!\n");
    }
}

void lowStockReport(int isbn[100], char titles[100][50], float prices[100], int quantities[100], int count){
    int found=0;
    printf("Low Stock Report");
    for(int i=0; i<count; i++){
        if(quantities[i]<5){
            printf("ISBN: %d | Title: %s | Price: %f | Quantity: %d", isbn[i], titles[i], prices[i], quantities[i]);
            found=1;
        }
    }
    if(!found)
        printf("All books have sufficient stock.");
}
