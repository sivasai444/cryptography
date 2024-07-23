#include <stdio.h>
#include <string.h>

void caesarCipher(char* text, int shift) {
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        }
        text[i] = c;
    }
}

int main() {
    char text[] = "HelloWorld";
    int shift = 3;
    caesarCipher(text, shift);
    printf("Encrypted text: %s\n", text);
    return 0;
}

