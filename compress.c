#include <stdio.h>
#include <zlib.h>
#include "compress.h"

void compressFile(const char *input, const char *output) {

    FILE *in = fopen(input, "rb");
    gzFile out = gzopen(output, "wb");

    char buffer[1024];
    int bytes;

    while((bytes = fread(buffer, 1, sizeof(buffer), in)) > 0) {
        gzwrite(out, buffer, bytes);
    }

    fclose(in);
    gzclose(out);

    printf("Compression done\n");
}