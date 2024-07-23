#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

long long power(long long a, long long b, long long P) {
    if (b == 1)
        return a;
    else
        return (((long long)pow(a, b)) % P);
}

int main() {
    long long P, G, x, a, y, k, m, C1, C2;

    printf("Enter the value of P: ");
    scanf("%lld", &P);
    printf("Enter the value of G: ");
    scanf("%lld", &G);

    printf("Enter the private key for Alice: ");
    scanf("%lld", &a);
    x = power(G, a, P);

    printf("Enter the message to be sent: ");
    scanf("%lld", &m);

    srand(time(0));
    k = rand() % P;

    C1 = power(G, k, P);
    C2 = (m * power(x, k, P)) % P;

    printf("Encrypted message: C1 = %lld, C2 = %lld\n", C1, C2);

    return 0;
}

