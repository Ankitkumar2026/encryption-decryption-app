#ifndef CRYPTO_H
#define CRYPTO_H

void encryptFile(const char *input, const char *output, const char *password);
void decryptFile(const char *input, const char *output, const char *password);

#endif