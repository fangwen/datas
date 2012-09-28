#ifndef _GRAPH_H
#define _GRAPH_H

#include <stdio.h>

#define MAX_POINT 583

typedef struct point {
	double x;
	double y;
} Point;

void dfs(double road[][MAX_POINT], int visited[], int v);
void dfs_traverse(double road[][MAX_POINT]);
void visit(double road[][MAX_POINT], int v);
void bfs_traverse(double road[][MAX_POINT]);

#endif
