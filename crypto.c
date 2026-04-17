#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include "crypto.h"

void encryptFile(const char *input, const char *output, const char *password) {

    FILE *in = fopen(input, "rb");
    FILE *out = fopen(output, "wb");

    if(!in || !out) {
        printf("File error\n");
        return;
    }

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    unsigned char key[32] = {0};
    unsigned char iv[16] = {0};

    strncpy((char*)key, password, 32);

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    unsigned char inbuf[1024], outbuf[1040];
    int inlen, outlen;

    while((inlen = fread(inbuf, 1, 1024, in)) > 0) {
        EVP_EncryptUpdate(ctx, outbuf, &outlen, inbuf, inlen);
        fwrite(outbuf, 1, outlen, out);
    }

    EVP_EncryptFinal_ex(ctx, outbuf, &outlen);
    fwrite(outbuf, 1, outlen, out);

    EVP_CIPHER_CTX_free(ctx);
    fclose(in);
    fclose(out);

    printf("Encryption done\n");
}

// 🔓 DECRYPT FUNCTION (IMPORTANT — THIS FIXES YOUR ERROR)

void decryptFile(const char *input, const char *output, const char *password) {

    FILE *in = fopen(input, "rb");
    FILE *out = fopen(output, "wb");

    if(!in || !out) {
        printf("File error\n");
        return;
    }

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    unsigned char key[32] = {0};
    unsigned char iv[16] = {0};

    strncpy((char*)key, password, 32);

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    unsigned char inbuf[1024], outbuf[1040];
    int inlen, outlen;

    while((inlen = fread(inbuf, 1, 1024, in)) > 0) {
        EVP_DecryptUpdate(ctx, outbuf, &outlen, inbuf, inlen);
        fwrite(outbuf, 1, outlen, out);
    }

    EVP_DecryptFinal_ex(ctx, outbuf, &outlen);
    fwrite(outbuf, 1, outlen, out);

    EVP_CIPHER_CTX_free(ctx);
    fclose(in);
    fclose(out);

    printf("Decryption done\n");
}