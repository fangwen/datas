graph: graph.o queue.o
	gcc -o graph graph.o queue.o -lm

graph.o: graph.c graph.h queue.h
	gcc -c graph.c

queue.o: queue.c queue.h
	gcc -c queue.c

clean:
	rm *.o
