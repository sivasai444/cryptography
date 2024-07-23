#include <stdio.h>

#define GRID_SIZE 5

// Function to display the Playfair matrix
void displayPlayfairMatrix(char matrix[GRID_SIZE][GRID_SIZE]) {
    printf("Playfair Matrix:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char playfairMatrix[GRID_SIZE][GRID_SIZE] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    displayPlayfairMatrix(playfairMatrix);

    return 0;
}

