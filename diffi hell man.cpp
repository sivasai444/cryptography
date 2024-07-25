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
    int a = 5;  // example base
    int q = 23; // example prime modulus
    int xa = 6; // Alice's private key
    int xb = 15; // Bob's private key

    int ya = modExp(a, xa, q); // Alice's public key
    int yb = modExp(a, xb, q); // Bob's public key

    int ka = modExp(yb, xa, q); // Alice's shared key
    int kb = modExp(ya, xb, q); // Bob's shared key

    printf("Alice's shared key: %d\n", ka);
    printf("Bob's shared key: %d\n", kb);

    return 0;
}

