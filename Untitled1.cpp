#include <stdio.h>
#include <string.h>

void pad_message(char *message, int block_size) {
    int len = strlen(message);
    int pad_len = block_size - (len % block_size);
    for (int i = 0; i < pad_len; i++) {
        message[len + i] = (i == 0) ? 1 : 0;
    }
    message[len + pad_len] = '\0';
}

int main() {
    char message[64] = "Padding is important for CBC mode.";
    int block_size = 8;

    printf("Original message: %s\n", message);
    pad_message(message, block_size);
    printf("Padded message: %s\n", message);

    return 0;
}

