#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 1024

void initializeState(int state[5][5]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            state[i][j] = 0;
}

void processBlock(int state[5][5], int block[BLOCK_SIZE]) {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            state[i][j] ^= block[i * 5 + j];
}

void displayState(int state[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            printf("%08x ", state[i][j]);
        printf("\n");
    }
}

int main() {
    int state[5][5];
    initializeState(state);

    int block[BLOCK_SIZE];
    srand(time(NULL));
    for (int i = 0; i < BLOCK_SIZE; i++)
        block[i] = rand();

    processBlock(state, block);
    displayState(state);

    return 0;
}

