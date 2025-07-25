#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
    }
}

int main() {
    char text[100];
    int shift;

    printf("Enter text to encrypt: ");
    fgets(text, sizeof(text), stdin);
    printf("Enter shift value: ");
    scanf("%d", &shift);

    encrypt(text, shift);
    printf("Encrypted text: %s\n", text);

    return 0;
}
