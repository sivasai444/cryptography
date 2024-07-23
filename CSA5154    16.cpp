#include <stdio.h>
#include <string.h>

void permuteDecrypt(char* text, int* key, int keyLen) {
    int len = strlen(text);
    char temp[len + 1];
    int k = 0;

    for (int i = 0; i < len; i += keyLen) {
        for (int j = 0; j < keyLen; j++) {
            temp[i + key[j] - 1] = text[i + j];
        }
    }
    temp[len] = '\0';
    strcpy(text, temp);
}

int main() {
    char text[100];
    int key[] = {3, 1, 4, 2}; // Example key, you can modify this
    int keyLen = sizeof(key) / sizeof(key[0]);

    printf("Enter the ciphertext: ");
    scanf("%s", text);

    permuteDecrypt(text, key, keyLen);

    printf("Decrypted text: %s\n", text);

    return 0;
}

