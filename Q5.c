#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    int i;
    for ( i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toggleBits(char *ch) {
    *ch = *ch ^ (1 << 1); 
    *ch = *ch ^ (1 << 4); 
}

void encodeMessage(char message[]) {
    reverseString(message);
    int i;
	for ( i = 0; message[i] != '\0'; i++) {
        toggleBits(&message[i]);
    }
    printf("\nEncoded message: %s\n\n", message);
}

void decodeMessage(char message[]) {
    int i;
	for ( i = 0; message[i] != '\0'; i++) {
        toggleBits(&message[i]);
    }
    reverseString(message);
    printf("Decoded message: %s\n", message);
}

int main() {
    char message[200];
    int choice;

    do {
        printf("\n--- TCS Secure Message System ---\n");
        printf("1. Encoded Message\n");
        printf("2. Decoded Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("\nEnter message to encode: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            encodeMessage(message);
        } 
        else if (choice == 2) {
            printf("\nEnter message to decode: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            decodeMessage(message);
        } 
        else if (choice == 3) {
            printf("\nExiting program...\n");
        } 
        else {
            printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}
