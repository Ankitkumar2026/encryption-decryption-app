#include <stdio.h>
#include "crypto.h"
#include "compress.h"

int main(int argc, char *argv[]) {

    if(argc != 5) {
        printf("Usage: prog input output password e/d\n");
        return 1;
    }

    if(argv[4][0] == 'e') {
        compressFile(argv[1], "temp.gz");
        encryptFile("temp.gz", argv[2], argv[3]);
    }
    else {
        decryptFile(argv[1], "temp.gz", argv[3]);
        printf("Now manually decompress temp.gz\n");
    }

    return 0;
}