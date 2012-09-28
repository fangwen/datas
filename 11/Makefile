huffman: main.o huffman.o bitio.o
	gcc -o huffman main.o huffman.o bitio.o

main.o: main.c huffman.h
	gcc -c main.c

huffman.o: huffman.c huffman.h bitio.h
	gcc -c huffman.c

bitio.o: bitio.c bitio.h
	gcc -c bitio.c

clean:
	rm *.o
