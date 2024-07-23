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

void vigenereEncrypt(char* str, char* key, char* encryptedText) {
    for (int i = 0; i < strlen(str); i++) {
        encryptedText[i] = ((str[i] + key[i]) % 26) + 'A';
    }
    encryptedText[strlen(str)] = '\0';
}

int main() {
    char str[100], key[100], encryptedText[100];

    printf("Enter the plaintext: ");
    scanf("%s", str);
    printf("Enter the key: ");
    scanf("%s", key);

    generateKey(str, key);
    vigenereEncrypt(str, key, encryptedText);

    printf("Encrypted text: %s\n", encryptedText);

    return 0;
}

