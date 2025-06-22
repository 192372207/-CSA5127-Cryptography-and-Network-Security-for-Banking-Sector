#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j = 0;
    int key_length = strlen(key);
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            ciphertext[i] = (plaintext[i] + key[j] - 2 * 'A') % 26 + 'A';
            j = (j + 1) % key_length;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[i] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100];
    
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0; 

    encrypt(plaintext, key, ciphertext);
    
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
