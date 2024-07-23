#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MATRIX_SIZE 2

// Function to convert a character to its corresponding number (A=0, B=1, ..., Z=25)
int charToNumber(char ch) {
    return toupper(ch) - 'A';
}

// Function to convert a number to its corresponding character (0=A, 1=B, ..., 25=Z)
char numberToChar(int num) {
    return num + 'A';
}

// Function to perform matrix multiplication for Hill cipher
void matrixMultiply(int key[MATRIX_SIZE][MATRIX_SIZE], int input[MATRIX_SIZE], int result[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i] += key[i][j] * input[j];
        }
        result[i] %= 26; // Modulo 26 operation
        if (result[i] < 0) {
            result[i] += 26; // Ensure positive result
        }
    }
}

// Function to encrypt using Hill cipher
void hillEncrypt(char *plaintext, int key[MATRIX_SIZE][MATRIX_SIZE]) {
    int length = strlen(plaintext);
    int padded_length = (length % MATRIX_SIZE == 0) ? length : length + (MATRIX_SIZE - length % MATRIX_SIZE);
    int num_blocks = padded_length / MATRIX_SIZE;
    int block[MATRIX_SIZE], result[MATRIX_SIZE];

    for (int i = 0; i < num_blocks; i++) {
        // Convert block of plaintext to numbers
        for (int j = 0; j < MATRIX_SIZE; j++) {
            block[j] = (i * MATRIX_SIZE + j < length) ? charToNumber(plaintext[i * MATRIX_SIZE + j]) : charToNumber('X');
        }

        // Perform matrix multiplication
        matrixMultiply(key, block, result);

        // Convert numbers back to characters and print
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%c", numberToChar(result[j]));
        }
    }
    printf("\n");
}


