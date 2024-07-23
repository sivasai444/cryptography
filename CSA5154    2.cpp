#include <stdio.h>
#include <string.h>

void monoalphabeticCipher(char* text, char* key) {
    for (int i = 0; i < strlen(text); i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            text[i] = key[c - 'a'];
        } else if (c >= 'A' && c <= 'Z') {
            text[i] = key[c - 'A'] - ('a' - 'A');
        }
    }
}

int main() {
    char text[] = "HelloWorld";
    char key[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    monoalphabeticCipher(text, key);
    printf("Encrypted text: %s\n", text);
    return 0;
}

