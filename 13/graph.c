#include <stdio.h>
#include "stack.h"

#define MAX 9

void key_path(int graph[][MAX])
{
	int graph2[MAX][MAX];
	int i;
	for (i = 0; i < MAX; i++) {
		int j;
		for (j = 0; j < MAX; j++)
			graph2[i][j] = graph[i][j];
	}

	stack sve, svl;
	init_stack(&sve, 100);
	init_stack(&svl, 100);
	int ve[MAX];
	for (i = 0; i < MAX; i++)
		ve[i] = 0;
	int j;
	for (j = 0; j < MAX; j++) {
		for (i = 0; i < MAX; i++) {
			if (graph2[i][j] != 0)
				break;
		}
		if (i == MAX)
			push(&sve, j);
	}

	while (stack_length(&sve)) {
		int s = pop(&sve);
		push(&svl, s);
		int n;

		for (n = 0; n < MAX; n++) {
			graph2[s][n] = 0;
			if (graph[s][n] != 0) {
				int l;
				for (l = 0; l < MAX; l++) {
					if (graph2[l][n] != 0)
						break;
				}
				if (l == MAX)
					push(&sve, n);
			}
		}

		int m;
		for (m = 0; m < MAX; m++) {
			if (graph[s][m] != 0)
				if (ve[s]+graph[s][m] > ve[m])
					ve[m] = ve[s] + graph[s][m];
		}
	}

	int vl[MAX];
	for (i = 0; i < MAX; i++)
		vl[i] = ve[MAX-1];
	int x;
	while (stack_length(&svl)) {
		int v = pop(&svl);
		for (x = 0; x < MAX; x++)
			if (graph[x][v] != 0)
				if ((vl[v] - graph[x][v]) < vl[x])
					vl[x] = vl[v] - graph[x][v];
	}

	int key[MAX];
	i = 0;
	int y;
	for (y = 0; y < MAX; y++) {
		if (ve[y] == vl[y]) {
			key[i] = y;
			i++;
		}
	}
	printf("all the key node: ");
	for (y = 0; y < i; y++)
		printf ("%d ", key[y]);
	printf("\n");

	printf("keypath: ");
	int prev = key[0];
	int next = key[1];
	int length = 0;
	int ne;
	while (1) {
		length += graph[prev][next];
		printf("%d ", prev);
		if (next == key[i-1]) {
			printf ("%d\n", next);
			break;
		}
		for (y = 0; y < i; y++) {
			ne = key[y];
			if (graph[next][ne] != 0 ) {
				prev = next;
				next = ne;
				break;
			}
		}
	}

	printf("keypath length: %d\n", length);
}

int main()
{
	int graph[MAX][MAX];
	int i;
	for (i = 0; i < MAX; i++) {
		int j;
		for (j = 0; j < MAX; j++)
			graph[i][j] = 0;
	}
	int row, col, weight;
	for (i = 0; i < 11; i++) {
		scanf("%d%d%d", &row, &col, &weight);
		graph[row][col] = weight;
	}
	key_path(graph);
	return 0;
}
