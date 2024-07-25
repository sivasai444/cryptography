#include <stdio.h>
#include <math.h>

int modExp(int base, int exp, int mod) {
    int result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int n = 61 * 53;  // example modulus
    int e = 17;       // example public key
    char message[] = "HELLO";  // example message

    printf("Encrypted message: ");
    for (int i = 0; message[i] != '\0'; i++) {
        int m = message[i] - 'A';
        int c = modExp(m, e, n);
        printf("%d ", c);
    }
    printf("\n");

    return 0;
}

