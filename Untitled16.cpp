#include <stdio.h>
#include <math.h>

long long int power(long long int a, long long int b, long long int P) {
    if (b == 1) {
        return a;
    } else {
        return (((long long int)pow(a, b)) % P);
    }
}

int main() {
    long long int P, G, x, a, y, b, ka, kb;

    printf("Enter the value of P: ");
    scanf("%lld", &P);
    printf("Enter the value of G: ");
    scanf("%lld", &G);

    printf("Enter the private key for Alice: ");
    scanf("%lld", &a);
    x = power(G, a, P);

    printf("Enter the private key for Bob: ");
    scanf("%lld", &b);
    y = power(G, b, P);

    ka = power(y, a, P);
    kb = power(x, b, P);

    printf("Secret key for Alice is: %lld\n", ka);
    printf("Secret key for Bob is: %lld\n", kb);

    return 0;
}

