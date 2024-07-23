#include <stdio.h>

void affineDecrypt(char* text, int a, int b) {
    int a_inv = 0;
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }

    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (a_inv * ((text[i] - 'a' - b + 26) % 26)) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (a_inv * ((text[i] - 'A' - b + 26) % 26)) % 26 + 'A';
        }
    }
}

int main() {
    char text[100];
    int a = 1, b = 0; // assumed values based on the provided information
    printf("Enter the ciphertext: ");
    gets(text);
    affineDecrypt(text, a, b);
    printf("Decrypted text: %s\n", text);
    return 0;
}

