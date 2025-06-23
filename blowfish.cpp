#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BLOCK_SIZE 8
#define NUM_ROUNDS 16
#define P_ARRAY_SIZE 18
#define S_BOX_SIZE 256
unsigned long P[P_ARRAY_SIZE];
unsigned long S[4][S_BOX_SIZE];
void initialize() {
}
void encrypt(unsigned long *left, unsigned long *right) {
    for (int i = 0; i < NUM_ROUNDS; i++) {
        *left ^= P[i];
        unsigned long temp = *left;
        *left = *right;
        *right = temp;
    }
    unsigned long temp = *left;
    *left = *right;
    *right = temp;
}
void decrypt(unsigned long *left, unsigned long *right) {
    for (int i = NUM_ROUNDS - 1; i >= 0; i--) {
        *left ^= P[i];
        unsigned long temp = *left;
        *left = *right;
        *right = temp;
    }
    unsigned long temp = *left;
    *left = *right;
    *right = temp;
}
int main() {
    initialize();
    unsigned long left = 0x01234567;
    unsigned long right = 0x89abcdef;
    printf("Original: %08lx %08lx\n", left, right);
    encrypt(&left, &right);
    printf("Encrypted: %08lx %08lx\n", left, right);
    decrypt(&left, &right);
    printf("Decrypted: %08lx %08lx\n", left, right);
    return 0;
}
