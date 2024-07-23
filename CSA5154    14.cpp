#include <stdio.h>
#include <string.h>

void generateKey(char* str, char* key) {
    int x = strlen(str);

    for (int i = 0, j = 0; i < x; i++, j++) {
        if (j == strlen(key))
            j = 0;
        key[i] = key[j];
    }
    key[x] = '\0';
}

void vigenereDecrypt(char* str, char* key, char* decryptedText) {
    for (int i = 0; i < strlen(str); i++) {
        decryptedText[i] = (((str[i] - key[i]) + 26) % 26) + 'A';
    }
    decryptedText[strlen(str)] = '\0';
}

int main() {
    char str[100], key[100], decryptedText[100];

    printf("Enter the ciphertext: ");
    scanf("%s", str);
    printf("Enter the key: ");
    scanf("%s", key);

    generateKey(str, key);
    vigenereDecrypt(str, key, decryptedText);

    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}

