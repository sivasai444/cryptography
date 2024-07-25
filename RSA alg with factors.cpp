#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int p = 61;  // example prime
    int q = 59;  // example prime
    int n = p * q;
    int e = 17;  // example public key
    int phi = (p - 1) * (q - 1);
    
    // Example plaintext that has a common factor with n
    int plaintext = 58;
    
    if (gcd(plaintext, n) != 1) {
        printf("The plaintext %d has a common factor with n=%d.\n", plaintext, n);
        // Example ciphertext
        int ciphertext = (int)int pow(plaintext, e) % n;
        printf("The ciphertext is %d\n", ciphertext);
    } else {
        printf("The plaintext %d does not have a common factor with n=%d.\n", plaintext, n);
    }

    return 0;
}

