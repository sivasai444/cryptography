#include <stdio.h>
#include <stdlib.h>

// Function to calculate gcd
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find modular inverse
int modInverse(int e, int phi) {
    int m0 = phi, t, q;
    int x0 = 0, x1 = 1;
    
    if (phi == 1)
        return 0;
    
    while (e > 1) {
        q = e / phi;
        t = phi;
        phi = e % phi;
        e = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    
    if (x1 < 0)
        x1 += m0;
    
    return x1;
}

int main() {
    int p = 61;  // example prime
    int q = 59;  // example prime
    int n = p * q;
    int phi = (p - 1) * (q - 1);
    int e = 17;  // example public key
    int d = modInverse(e, phi);  // private key
    
    printf("Public key: (%d, %d)\n", e, n);
    printf("Private key: (%d, %d)\n", d, n);
    
    // Bob leaks his private key
    d = modInverse(e, phi);  // new private key
    printf("New private key: (%d, %d)\n", d, n);

    return 0;
}

