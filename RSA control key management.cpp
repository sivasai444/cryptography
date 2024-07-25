#include <stdio.h>

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

int extended_euclid(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extended_euclid(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int mod_inverse(int e, int phi) {
    int x, y;
    int g = extended_euclid(e, phi, &x, &y);
    if (g != 1) {
        return -1;
    } else {
        return (x % phi + phi) % phi;
    }
}

int main() {
    int e = 31;
    int n = 3599;
    int p = 59;
    int q = 61;
    int phi = (p - 1) * (q - 1);
    int d = mod_inverse(e, phi);

    if (d == -1) {
        printf("No modular inverse found.\n");
    } else {
        printf("Private key (d): %d\n", d);
    }

    return 0;
}

