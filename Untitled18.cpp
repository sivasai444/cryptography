#include <stdio.h>
#include <math.h>

long long int power(long long int a, long long int b, long long int P) {
    if (b == 1) {
        return a;
    } else {
        return (((long long int)pow(a, b)) % P);
    }
}

int gcd(int a, int b) {
    int t;
    while (1) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

int main() {
    double p = 3;
    double q = 7;
    double n = p * q;
    double e = 2;
    double phi = (p - 1) * (q - 1);

    while (e < phi) {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }

    double d1 = 1 / e;
    double d = fmod(d1, phi);
    double message = 12;
    double c = pow(message, e);
    double m = pow(c, d);
    c = fmod(c, n);
    m = fmod(m, n);

    printf("Encrypted Message = %lf\n", c);
    printf("Decrypted Message = %lf\n", m);

    return 0;
}

