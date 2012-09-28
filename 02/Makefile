all: swap union unique equal unique2 bigger
swap: list.o swap.o
	gcc -o swap list.o swap.o
union: list.o union.o
	gcc -o union list.o union.o
unique: list.o unique.o
	gcc -o unique list.o unique.o
equal: list.o equal.o
	gcc -o equal list.o equal.o
unique2: list.o unique2.o
	gcc -o unique2 list.o unique2.o
bigger: list.o bigger.o
	gcc -o bigger list.o bigger.o
list.o: list.c list.h
	gcc -c list.c
swap.o: swap.c list.h
	gcc -c swap.c
union.o: union.c list.h
	gcc -c union.c
unique.o: unique.c list.h
	gcc -c unique.c
equal.o: equal.c list.h
	gcc -c equal.c
unique2.o: unique2.c list.h
	gcc -c unique2.c
bigger.o: bigger.c list.h
	gcc -c bigger.c
