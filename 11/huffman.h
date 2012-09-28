#ifndef _HUFFMAN_H
#define _HUFFMAN_H

#include <stdio.h>
#include "bitio.h"

#define SEEK_SET 0
#define END_OF_STREAM 256

typedef struct tree_node {
    unsigned int count;
    int child_0;
    int child_1;
} NODE;

typedef struct code {
    unsigned int code;
    int code_bits;
} CODE;

void count_bytes(FILE *input, int *counts);
void give_node_count(NODE *nodes, int *counts);
int build_tree(NODE *nodes);
void convert_tree_to_code(NODE *nodes, CODE *codes,
						  unsigned int code_so_far, int bits, int node);
void compress_data(FILE *input, BIT_FILE *output, CODE *codes);
void output_counts(BIT_FILE *output, int *counts);
void compress(FILE *input, BIT_FILE *output);
void decompress_data(BIT_FILE *input, FILE *output, NODE *nodes, int root_node);
void decompress(BIT_FILE *input, FILE *output);

#endif
