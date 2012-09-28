#include <stdio.h>
#include <stdlib.h>
#include "bitio.h"

BIT_FILE *open_input_bitfile(char *name)
{
    BIT_FILE *bit_file;
    bit_file = (BIT_FILE *) malloc(sizeof(BIT_FILE));
    if (bit_file == NULL)
        return bit_file;
    bit_file->file = fopen(name, "r");
    bit_file->rack = 0;
    bit_file->mask = 0x80;
    return bit_file;
}

BIT_FILE *open_output_bitfile(char *name)
{
    BIT_FILE *bit_file;
    bit_file = (BIT_FILE *) malloc(sizeof(BIT_FILE));
    if (bit_file == NULL)
        return bit_file;
    bit_file->file = fopen(name, "w");
    bit_file->rack = 0;
    bit_file->mask = 0x80;
    return bit_file;
}

void close_input_bitfile(BIT_FILE *bit_file)
{
    fclose(bit_file->file);
    free(bit_file);
}

void close_output_bitfile(BIT_FILE *bit_file)
{
    if (bit_file->mask != 0x80)
        if (putc(bit_file->rack, bit_file->file) != bit_file->rack)
            printf("error in close_output_bitfile!\n");
    fclose(bit_file->file);
    free(bit_file);
}

int input_bit(BIT_FILE *bit_file)
{
    int bit;
    if (bit_file->mask == 0x80) {
        bit_file->rack = getc(bit_file->file);
        if (bit_file->rack == EOF)
            printf("error in input_bit!\n");
    }
    bit = bit_file->rack & bit_file->mask;
    bit_file->mask >>= 1;
    if (bit_file->mask == 0)
        bit_file->mask = 0x80;
    return bit ? 1 : 0;
}

void output_bit(BIT_FILE *bit_file, int bit)
{
    if (bit)
        bit_file->rack |= bit_file->mask;
    bit_file->mask >>= 1;
    if (bit_file->mask == 0) {
        if (putc(bit_file->rack, bit_file->file) != bit_file->rack)
            printf("error in output_bit!\n");
        bit_file->rack = 0;
        bit_file->mask = 0x80;
    }
}

void output_bits(BIT_FILE *bit_file, unsigned long code, int count)
{
    unsigned long mask;
    mask = 1L << (count - 1);
    while (mask != 0) {
        if (mask & code)
            bit_file->rack |= bit_file->mask;
        bit_file->mask >>= 1;
        if (bit_file->mask == 0) {
            if (putc(bit_file->rack, bit_file->file) != bit_file->rack)
                printf("error in output_bits!\n");
            bit_file->rack = 0;
            bit_file->mask = 0x80;
        }
        mask >>= 1;
    }
}
