#include <stdio.h>
#include <openssl/bn.h>

void elgamal_encrypt() {
    BIGNUM* p = BN_new();
    BIGNUM* g = BN_new();
    BIGNUM* x = BN_new();
    BIGNUM* y = BN_new();
    BN_CTX* ctx = BN_CTX_new();

    // Example prime and generator
    BN_set_word(p, 23);
    BN_set_word(g, 5);

    // Private key
    BN_rand(x, 128, 0, 0);
    BN_mod_exp(y, g, x, p, ctx);

    // Message
    BIGNUM* m = BN_new();
    BN_set_word(m, 19);

    // Random k
    BIGNUM* k = BN_new();
    BN_rand(k, 128, 0, 0);

    // Encryption
    BIGNUM* a = BN_new();
    BIGNUM* b = BN_new();
    BN_mod_exp(a, g, k, p, ctx);
    BN_mod_exp(b, y, k, p, ctx);
    BN_mod_mul(b, b, m, p, ctx);

    printf("Encrypted: (a, b) = (%s, %s)\n", BN_bn2dec(a), BN_bn2dec(b));

    BN_free(p);
    BN_free(g);
    BN_free(x);
    BN_free(y);
    BN_free(m);
    BN_free(k);
    BN_free(a);
    BN_free(b);
    BN_CTX_free(ctx);
}

int main() {
    elgamal_encrypt();
    return 0;
}

