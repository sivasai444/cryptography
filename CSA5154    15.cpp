#include <stdio.h>
#include <string.h>

void permuteEncrypt(char* text, int* key, int keyLen) {
    int len = strlen(text);
    char temp[len + 1];
    int k = 0;

    for (int i = 0; i < len; i += keyLen) {
        for (int j = 0; j < keyLen; j++) {
            temp[i + j] = text[i + key[j] - 1];
        }
    }
    temp[len] = '\0';
    strcpy(text, temp);
}

int main() {
    char text[100];
    int key[] = {3, 1, 4, 2}; // Example key, you can modify this
    int keyLen = sizeof(key) / sizeof(key[0]);

    printf("Enter the plaintext: ");
    scanf("%s", text);

    permuteEncrypt(text, key, keyLen);

    printf("Encrypted text: %s\n", text);

    return 0;
}

