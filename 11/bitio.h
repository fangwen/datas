#ifndef _BITIO_H
#define _BITIO_H

#include <stdio.h>

typedef struct bit_file {
    FILE *file;
    int rack;
    unsigned char mask;
} BIT_FILE;

BIT_FILE *open_input_bitfile(char *name);
BIT_FILE *open_output_bitfile(char *name);
void close_input_bitfile(BIT_FILE *bit_file);
void close_output_bitfile(BIT_FILE *bit_file);
int input_bit(BIT_FILE *bit_file);
void output_bit(BIT_FILE *bit_file, int bit);
void output_bits(BIT_FILE *bit_file, unsigned long code, int count);

#endif
