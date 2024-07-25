#include <stdio.h>
#include <openssl/dsa.h>
#include <openssl/err.h>

void generate_dsa_key() {
    DSA* dsa = DSA_new();
    if (DSA_generate_parameters_ex(dsa, 1024, NULL, 0, NULL, NULL, NULL)) {
        if (DSA_generate_key(dsa)) {
            printf("DSA key generated.\n");
        }
    }
    DSA_free(dsa);
}

int main() {
    generate_dsa_key();
    return 0;
}

