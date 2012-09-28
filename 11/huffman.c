#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bitio.h"
#include "huffman.h"

/* count the frequence of every byte in the input file */
void count_bytes(FILE *input, int *counts)
{
    int input_marker;
    int c;
    input_marker = ftell(input);
    while ((c = getc(input)) != EOF)
        counts[c]++;
    counts[END_OF_STREAM] = 1;
    fseek(input, input_marker, SEEK_SET);
}

void give_node_count(NODE *nodes, int *counts)
{
    int i;
    for (i = 0; i <= END_OF_STREAM; i++) {
        nodes[i].count = counts[i];
    }
}

/* build the huffman tree for decoding */
int build_tree(NODE *nodes)
{
    int next_free;
    int i;
    int min_1;
    int min_2;
    nodes[513].count = 0xffff;	/* of type unsigned int */
    for (next_free = END_OF_STREAM + 1; ; next_free++) {
        min_1 = 513;
        min_2 = 513;
        for (i = 0; i < next_free; i++)
            if (nodes[i].count != 0) {
                if (nodes[i].count < nodes[min_1].count) {
                    min_2 = min_1;
                    min_1 = i;
                } else if (nodes[i].count < nodes[min_2].count)
                    min_2 = i;
            }
        if (min_2 == 513)
            break;
        nodes[next_free].count = nodes[min_1].count + nodes[min_2].count;
        nodes[min_1].count = 0;
        nodes[min_2].count = 0;
        nodes[next_free].child_0 = min_1;
        nodes[next_free].child_1 = min_2;
    }
    next_free--;
    return next_free;
}

/* convert huffman tree to code table for encoding */
void convert_tree_to_code(NODE *nodes, CODE *codes,
                          unsigned int code_so_far, int bits, int node)
{
    if (node <= END_OF_STREAM) {
        codes[node].code = code_so_far;
        codes[node].code_bits = bits;
        return;
    }
    code_so_far <<= 1;
    bits++;
    convert_tree_to_code(nodes, codes, code_so_far
                         , bits,
                         nodes[node].child_0);
    convert_tree_to_code(nodes, codes, code_so_far | 1, bits,
                         nodes[node].child_1);
}

/* read in each byte, sent out its corresponding huffman code */
void compress_data(FILE *input, BIT_FILE *output, CODE *codes)
{
    int c;
    while ((c = getc(input)) != EOF)
        output_bits(output, (unsigned long) codes[c].code,
                    codes[c].code_bits);
    output_bits(output, (unsigned long) codes[END_OF_STREAM].code,
                codes[END_OF_STREAM].code_bits);
}

void output_counts(BIT_FILE *output, int *counts)
{
    int i;
    for (i = 0; i <= 256; i++) {
        fprintf(output->file, "%d", counts[i]);
        fprintf(output->file, "%s", " ");
    }
}

void compress(FILE *input, BIT_FILE *output)
{
    int *counts;
    NODE *nodes;
    CODE *codes;
    int root_node;
    if ((counts = (int *) malloc(256 * sizeof(int))) == NULL)
		printf("error allocating counts array \n");
    if ((nodes = (NODE *) malloc(514 * sizeof(NODE))) == NULL)
        printf("error allocating nodes array\n");
    if ((codes = (CODE *) malloc(257 * sizeof(CODE))) == NULL)
        printf("error allocating codes array\n");
    count_bytes(input, counts);
    give_node_count(nodes, counts);
    root_node = build_tree(nodes);
	convert_tree_to_code(nodes, codes, 0, 0, root_node);
    output_counts(output, counts);
    compress_data(input, output, codes);
    free(counts);
    free(nodes);
    free(codes);
}

void decompress_data(BIT_FILE *input, FILE *output, NODE *nodes, int root_node)
{
    int node;
    for (;;) {
        node = root_node;
        do {
            if (input_bit(input))
                node = nodes[node].child_1;
            else
                node = nodes[node].child_0;
        } while (node > END_OF_STREAM);
        if (node == END_OF_STREAM)
            break;
        if ((putc(node, output)) != node)
            printf("error trying to write byte to output\n");
    }
}

void decompress(BIT_FILE *input, FILE *output)
{
    NODE *nodes;
    int root_node;
    if ((nodes = (NODE *) malloc(514 * sizeof(NODE))) == NULL)
        printf("error allocating nodes array\n");
    int i, j;
    for (i = 0; i <= END_OF_STREAM; i++) {
        fscanf(input->file, "%d", &j);
        nodes[i].count = j;
    }
    root_node = build_tree(nodes);
    fseek(input->file, 1, 1);
    decompress_data(input, output, nodes, root_node);
    free(nodes);
}
