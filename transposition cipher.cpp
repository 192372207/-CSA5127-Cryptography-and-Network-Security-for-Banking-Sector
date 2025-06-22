#include <stdio.h>
#include <string.h>

void encrypt(char *message, int key) {
    int len = strlen(message);
    char encrypted[len + 1];
    int index = 0;

    for (int i = 0; i < key; i++) {
        for (int j = i; j < len; j += key) {
            encrypted[index++] = message[j];
        }
    }
    encrypted[index] = '\0';
    printf("Encrypted Message: %s\n", encrypted);
}

void decrypt(char *encrypted, int key) {
    int len = strlen(encrypted);
    char decrypted[len + 1];
    int index = 0;

    for (int i = 0; i < key; i++) {
        for (int j = i; j < len; j += key) {
            decrypted[j] = encrypted[index++];
        }
    }
    decrypted[len] = '\0';
    printf("Decrypted Message: %s\n", decrypted);
}

int main() {
    char message[] = "VINOD KUMAR";
    int key = 3;

    encrypt(message, key);
    char encrypted[] = "HLOOL ELWRD"; 
    decrypt(encrypted, key);

    return 0;
}
