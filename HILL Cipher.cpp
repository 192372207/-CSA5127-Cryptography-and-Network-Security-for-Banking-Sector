#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

void encrypt(int key[MAX][MAX], int plaintext[MAX], int ciphertext[MAX], int n) {
    for (int i = 0; i < n; i++) {
        ciphertext[i] = 0;
        for (int j = 0; j < n; j++) {
            ciphertext[i] += key[i][j] * plaintext[j];
        }
        ciphertext[i] = ciphertext[i] % 26;
    }
}

void hillCipher(int key[MAX][MAX], char *plaintext, char *ciphertext, int n) {
    int pt[MAX], ct[MAX];
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        pt[i] = plaintext[i] - 'A';
    }
    encrypt(key, pt, ct, n);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = ct[i] + 'A';
    }
    ciphertext[len] = '\0';
}

int main() {
    int key[MAX][MAX] = { {6, 24, 1}, {13, 16, 10}, {20, 17, 15} };
    char plaintext[] = "ACT";
    char ciphertext[MAX];

    hillCipher(key, plaintext, ciphertext, 3);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}
