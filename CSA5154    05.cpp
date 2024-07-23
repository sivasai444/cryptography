#include <stdio.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 0)
            return x;
    }
    return -1;
}

void affineCipher(char* text, int a, int b, int m, int encrypt) {
    int a_inv = modInverse(a, m);
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (c >= 'a' && c <= 'z') {
            if (encrypt)
                c = (a * (c - 'a') + b) % m + 'a';
            else
                c = (a_inv * (c - 'a' - b + m)) % m + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            if (encrypt)
                c = (a * (c - 'A') + b) % m + 'A';
            else
                c = (a_inv * (c - 'A' - b + m)) % m + 'A';
        }
        text[i] = c;
    }
}

int main() {
    char text[] = "HelloWorld";
    int a = 5, b = 8, m = 26;
    
    affineCipher(text, a, b, m, 1);
    printf("Encrypted text: %s\n", text);
    
    affineCipher(text, a, b, m, 0);
    printf("Decrypted text: %s\n", text);
    
    return 0;
}

