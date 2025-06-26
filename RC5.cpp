#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define R 12
#define T 2*(R+1)
uint32_t S[T];
uint32_t rotl(uint32_t x, uint32_t y) { return (x << (y & 31)) | (x >> (32 - (y & 31))); }
void key_schedule(uint8_t *key) {
    uint32_t L[4] = {0}, P = 0xB7E15163, Q = 0x9E3779B9;
    for (int i = 15; i >= 0; i--) L[i/4] = (L[i/4] << 8) + key[i];
    S[0] = P; for (int i = 1; i < T; i++) S[i] = S[i - 1] + Q;
    uint32_t A = 0, B = 0; int i = 0, j = 0;
    for (int k = 0; k < 3 * T; k++) {
        A = S[i] = rotl(S[i] + A + B, 3);
        B = L[j] = rotl(L[j] + A + B, A + B);
        i = (i + 1) % T; j = (j + 1) % 4;
    }
}
void encrypt(uint32_t *pt, uint32_t *ct) {
    uint32_t A = pt[0] + S[0], B = pt[1] + S[1];
    for (int i = 1; i <= R; i++) {
        A = rotl(A ^ B, B) + S[2 * i];
        B = rotl(B ^ A, A) + S[2 * i + 1];
    }
    ct[0] = A; ct[1] = B;
}
int main() {
    uint8_t key[17]; uint32_t pt[2], ct[2];
    printf("Enter 16-character key: "); scanf("%16s", key);
    printf("Enter two 32-bit integers (plaintext): "); scanf("%u %u", &pt[0], &pt[1]);
    key_schedule(key);
    encrypt(pt, ct);
    printf("Encrypted: %08X %08X\n", ct[0], ct[1]);
    return 0;
}