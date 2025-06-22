#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, char *ciphertext, char *key) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            ciphertext[i] = key[plaintext[i] - 'a'];
        } else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = key[plaintext[i] - 'A'] - 32; // Convert to uppercase
        } else {
            ciphertext[i] = plaintext[i]; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null-terminate the ciphertext
}

int main() {
    char plaintext[] = "Hello World";
    char key[] = "qwertyuiopasdfghjklzxcvbnm"; // Example key
    char ciphertext[100];

    encrypt(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
