#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void generateKeyTable(char* key, char keyTable[SIZE][SIZE]) {
    int map[26] = {0};
    int x = 0, y = 0;
    
    for (int i = 0; key[i]; i++) {
        if (key[i] != 'j' && !map[key[i] - 'a']) {
            keyTable[x][y++] = key[i];
            map[key[i] - 'a'] = 1;
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch != 'j' && !map[ch - 'a']) {
            keyTable[x][y++] = ch;
            map[ch - 'a'] = 1;
            if (y == SIZE) {
                y = 0;
                x++;
            }
        }
    }
}

void digraph(char text[], char digraphs[][2], int* n) {
    int len = strlen(text);
    int k = 0;
    
    for (int i = 0; i < len; i += 2) {
        if (text[i] == text[i + 1]) {
            digraphs[k][0] = text[i];
            digraphs[k][1] = 'x';
            k++;
            i--;
        } else {
            digraphs[k][0] = text[i];
            digraphs[k][1] = text[i + 1];
            k++;
        }
    }
    *n = k;
}

void playfairCipher(char* text, char keyTable[SIZE][SIZE], int encrypt) {
    char digraphs[50][2];
    int n;
    digraph(text, digraphs, &n);
    
    for (int k = 0; k < n; k++) {
        char a = digraphs[k][0], b = digraphs[k][1];
        int x1, y1, x2, y2;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (keyTable[i][j] == a) {
                    x1 = i;
                    y1 = j;
                } else if (keyTable[i][j] == b) {
                    x2 = i;
                    y2 = j;
                }
            }
        }

        if (x1 == x2) {
            digraphs[k][0] = keyTable[x1][(y1 + encrypt) % SIZE];
            digraphs[k][1] = keyTable[x2][(y2 + encrypt) % SIZE];
        } else if (y1 == y2) {
            digraphs[k][0] = keyTable[(x1 + encrypt) % SIZE][y1];
            digraphs[k][1] = keyTable[(x2 + encrypt) % SIZE][y2];
        } else {
            digraphs[k][0] = keyTable[x1][y2];
            digraphs[k][1] = keyTable[x2][y1];
        }
    }

    for (int k = 0; k < n; k++) {
        printf("%c%c ", digraphs[k][0], digraphs[k][1]);
    }
    printf("\n");
}

int main() {
    char text[] = "helloworld";
    char key[] = "keyword";
    char keyTable[SIZE][SIZE];

    generateKeyTable(key, keyTable);

    printf("Encrypted text: ");
    playfairCipher(text, keyTable, 1);

    printf("Decrypted text: ");
    playfairCipher(text, keyTable, -1);

    return 0;
}

