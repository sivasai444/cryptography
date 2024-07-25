#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

void hmac_sha1(const char* key, const char* data, unsigned char* result) {
    unsigned int len = SHA_DIGEST_LENGTH;
    HMAC_CTX* ctx = HMAC_CTX_new();
    HMAC_Init_ex(ctx, key, strlen(key), EVP_sha1(), NULL);
    HMAC_Update(ctx, (unsigned char*)data, strlen(data));
    HMAC_Final(ctx, result, &len);
    HMAC_CTX_free(ctx);
}

int main() {
    const char* key = "secretkey";
    const char* data = "This is a test message";
    unsigned char result[SHA_DIGEST_LENGTH];
    
    hmac_sha1(key, data, result);

    printf("HMAC-SHA1: ");
    for (int i = 0; i < SHA_DIGEST_LENGTH; i++) {
        printf("%02x", result[i]);
    }
    printf("\n");

    return 0;
}

