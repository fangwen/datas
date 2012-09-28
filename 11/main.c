#include <stdio.h>
#include "huffman.h"

int main(int argv, char *argc[])
{
    printf("hello, this is a naive huffman compress and decompress program\n");

	if (!strcmp(argc[1], "-x")) {
        BIT_FILE *in = open_input_bitfile(argc[2]);
        FILE *output = fopen("dehuff", "w");
        decompress(in, output);
        fclose(output);
        close_input_bitfile(in);
    }

    if (!strcmp(argc[1], "-c")) {
		FILE *in = fopen(argc[2], "r");
		BIT_FILE *out = open_output_bitfile("huff");
		compress(in, out);
		close_output_bitfile(out);
		fclose(in);
    }

    printf("it\'s naive, isn't it?\n");
    return 0;
}
