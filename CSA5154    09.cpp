#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GRID_SIZE 5

// Function to remove spaces and convert to uppercase
void sanitizeInput(char *input) {
    int i, j = 0;
    for (i = 0; input[i]; i++) {
        if (input[i] != ' ') {
            input[j++] = toupper(input[i]);
        }
    }
    input[j] = '\0';
}

// Function to find the position of a character in the Playfair grid
void findPosition(char grid[GRID_SIZE][GRID_SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // treat 'J' as 'I'

    for (*row = 0; *row < GRID_SIZE; (*row)++) {
        for (*col = 0; *col < GRID_SIZE; (*col)++) {
            if (grid[*row][*col] == ch) {
                return;
            }
        }
    }
}

// Function to decrypt the Playfair cipher message
void decryptPlayfair(char *ciphertext, char *keyword) {
    char grid[GRID_SIZE][GRID_SIZE];
    char plaintext[strlen(ciphertext)];
    int row1, col1, row2, col2;

    // Remove spaces and convert ciphertext to uppercase
    sanitizeInput(ciphertext);
    sanitizeInput(keyword);

    // Build the Playfair cipher grid based on the keyword
    int len = strlen(keyword);
    int used[26] = {0};
    int index = 0;

    // Fill the grid with the keyword (without duplicates)
    for (int i = 0; i < len; i++) {
        if (keyword[i] == 'J') keyword[i] = 'I'; // treat 'J' as 'I'
        if (!used[keyword[i] - 'A']) {
            grid[index / GRID_SIZE][index % GRID_SIZE] = keyword[i];
            used[keyword[i] - 'A'] = 1;
            index++;
        }
    }

    // Fill the grid with remaining letters (excluding 'J')
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c != 'J' && !used[c - 'A']) {
            grid[index / GRID_SIZE][index % GRID_SIZE] = c;
            used[c - 'A'] = 1;
            index++;
        }
    }

    // Decrypt the ciphertext
    int length = strlen(ciphertext);
    int pair_count = 0;

    for (int i = 0; i < length; i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];

        // Find positions of letters in the grid
        findPosition(grid, a, &row1, &col1);
        findPosition(grid, b, &row2, &col2);

        if (row1 == row2) {
            // Same row
            plaintext[pair_count++] = grid[row1][(col1 + GRID_SIZE - 1) % GRID_SIZE];
            plaintext[pair_count++] = grid[row2][(col2 + GRID_SIZE - 1) % GRID_SIZE];
        } else if (col1 == col2) {
            // Same column
            plaintext[pair_count++] = grid[(row1 + GRID_SIZE - 1) % GRID_SIZE][col1];
            plaintext[pair_count++] = grid[(row2 + GRID_SIZE - 1) % GRID_SIZE][col2];
        } else {
            // Form a rectangle
            plaintext[pair_count++] = grid[row1][col2];
            plaintext[pair_count++] = grid[row2][col1];
        }
    }

    plaintext[pair_count] = '\0'; // Null-terminate the plaintext string
    printf("Decrypted Message:\n%s\n", plaintext);
}

int main() {
    char ciphertext[] = "KXJEY UREBE ZWEHE WRYTU HEYFS KREHE GOYFI WTTTU OLKSY CAJPO BOTEI ZONTX BYBNT GONEY CUZWR GDSON SXBOU YWRHE BAAHY USEDQ";
    char keyword[] = "PLAYFAIR"; // Example keyword (can be changed)

    decryptPlayfair(ciphertext, keyword);

    return 0;
}

