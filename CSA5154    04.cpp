#include <stdio.h>
#include <string.h>

void vigenereCipher(char* text, char* key, int encrypt) {
    int keyLen = strlen(key);
    for (int i = 0, j = 0; i < strlen(text); i++) {
        char c = text[i];
        int shift = (encrypt ? 1 : -1) * (key[j % keyLen] - 'a');
        
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift + 26) % 26 + 'a';
            j++;
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift + 26) % 26 + 'A';
            j++;
        }
        
        text[i] = c;
    }
}

int main() {
    char text[] = "HelloWorld";
    char key[] = "key";
    
    vigenereCipher(text, key, 1);
    printf("Encrypted text: %s\n", text);
    
    vigenereCipher(text, key, -1);
    printf("Decrypted text: %s\n", text);
    
    return 0;
}

