#include <stdio.h>
#include <string.h>

void getCustomerInfo(char name[], char cnic[]);
void displayInventory(int codes[], int qty[], float price[], int count);
void addToCart(int codes[], int qty[], float price[], int *count, int cartCodes[], int cartQty[], float cartPrice[], int *cartCount);
void updateInventory(int codes[], int qty[], int code, int q, int count);
void displayBill(int cartCodes[], int cartQty[], float cartPrice[], int cartCount, float *total, float *discountedTotal, int *discountApplied);
void showInvoice(char name[], char cnic[], int cartCodes[], int cartQty[], float cartPrice[], int cartCount, float total, float discountedTotal, int discountApplied);

int main() {
    int codes[4] = {1, 2, 3, 4};
    int qty[4] = {50, 10, 20, 8};
    float price[4] = {100, 200, 300, 150};
    int count = 4;

    int cartCodes[100];
    int cartQty[100];
    float cartPrice[100];
    int cartCount = 0;

    char name[50], cnic[20];
    float total = 0, discountedTotal = 0;
    int discountApplied = 0;

    int choice;

    do {
        printf("\nSUPERMARKET SYSTEM\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
            getCustomerInfo(name, cnic);
        else if (choice == 2)
            displayInventory(codes, qty, price, count);
        else if (choice == 3)
            addToCart(codes, qty, price, &count, cartCodes, cartQty, cartPrice, &cartCount);
        else if (choice == 4)
            displayBill(cartCodes, cartQty, cartPrice, cartCount, &total, &discountedTotal, &discountApplied);
        else if (choice == 5)
            showInvoice(name, cnic, cartCodes, cartQty, cartPrice, cartCount, total, discountedTotal, discountApplied);
        else if (choice == 6)
            printf("\nExiting system... Goodbye!\n");
        else
            printf("Invalid choice! Try again.\n");

    } while (choice != 6);

    return 0;
}

void getCustomerInfo(char name[], char cnic[]) {
    printf("\nEnter Customer Name: ");
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Enter CNIC Number: ");
    fgets(cnic, 20, stdin);
    cnic[strcspn(cnic, "\n")] = '\0';
    printf("Customer info saved successfully.\n");
}

void displayInventory(int codes[], int qty[], float price[], int count) {
    printf("\nINVENTORY\n");
    printf("Code\tQuantity\tPrice\n");
    printf("----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%03d\t%d\t\t%.2f\n", codes[i], qty[i], price[i]);
    }
}

void updateInventory(int codes[], int qty[], int code, int q, int count) {
    for (int i = 0; i < count; i++){
        if (codes[i] == code){
            qty[i] -= q;
            if (qty[i] < 0)
            qty[i] = 0;
            break;
        }
    }
}

void addToCart(int codes[], int qty[], float price[], int *count, int cartCodes[], int cartQty[], float cartPrice[], int *cartCount){
    int code, q, found = 0;
    displayInventory(codes, qty, price, *count);

    printf("\nEnter product code: ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &q);

    for (int i = 0; i < *count; i++){
        if (codes[i] == code) {
            found = 1;
            if (q <= qty[i]){
                cartCodes[*cartCount] = code;
                cartPrice[*cartCount] = price[i];
                cartQty[*cartCount] = q;
                (*cartCount)++;
                updateInventory(codes, qty, code, q, *count);
                printf("Item added to cart successfully!\n");
            } else{
                printf("Insufficient stock!\n");
            }
            break;
        }
    }
    if (!found)
    printf("Invalid product code!\n");
}

void displayBill(int cartCodes[], int cartQty[], float cartPrice[], int cartCount, float *total, float *discountedTotal, int *discountApplied) {
    *total = 0;
    printf("\n---- CART ----\n");
    printf("Code\tPrice\tQty\tTotal\n");
    printf("-----------------------------\n");
    for (int i = 0; i < cartCount; i++){
        float itemTotal = cartPrice[i] * cartQty[i];
        *total += itemTotal;
        printf("%03d\t%.2f\t%d\t%.2f\n", cartCodes[i], cartPrice[i], cartQty[i], itemTotal);
    }
    printf("\nTotal Bill: Rs. %.2f\n", *total);

    char ans[5], promo[20];
    printf("Do you have a promo code? (yes/no): ");
    scanf("%s", ans);

    if (strcmp(ans, "yes") == 0) {
        printf("Enter promo code: ");
        scanf("%s", promo);
        if (strcmp(promo, "Eid2025") == 0) {
            *discountApplied = 1;
            *discountedTotal = *total * 0.75;
            printf("Promo applied! 25%% discount.\n");
            printf("Discounted Bill: Rs. %.2f\n", *discountedTotal);
        } else {
            printf("Invalid promo code.\n");
            *discountedTotal = *total;
        }
    } else {
        *discountedTotal = *total;
    }
}

void showInvoice(char name[], char cnic[], int cartCodes[], int cartQty[], float cartPrice[], 
                 int cartCount, float total, float discountedTotal, int discountApplied) {
    if (total == 0) {
        printf("\nNo items purchased yet!\n");
        return;
    }

    printf("\n========== INVOICE ==========\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("\nItems Purchased:\n");
    printf("Code\tPrice\tQty\tTotal\n");
    for (int i = 0; i < cartCount; i++) {
        printf("%03d\t%.2f\t%d\t%.2f\n", cartCodes[i], cartPrice[i], cartQty[i], cartPrice[i] * cartQty[i]);
    }
    printf("\nTotal (No Discount): Rs. %.2f\n", total);
    if (discountApplied)
        printf("Discounted Total: Rs. %.2f\n", discountedTotal);
    else
        printf("No discount applied.\n");
    printf("=============================\n");
}
