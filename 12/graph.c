#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"
#include "graph.h"

void dfs(double road[][MAX_POINT], int visited[], int v)
{
	double average = 0.0;
	int arc = 0;
	int i;
	for (i = 1; i < MAX_POINT; i++) {
		average += road[v][i];
		if (road[v][i] > 0.0001)
			arc++;
	}
	average /= arc;
	printf ("%d, %.4f\n", v, average);
	visited[v] = 1;
	int j;
	for (j = 1; j < MAX_POINT; j++) {
		if (road[v][j] != 0 && !visited[j])
			dfs(road, visited, j);
	}
}

void dfs_traverse(double road[][MAX_POINT])
{
	int visited[MAX_POINT];
	int i;
	for (i = 1; i < MAX_POINT; i++)
		visited[i] = 0;
	for (i = 1; i < MAX_POINT; i++) {
		if (!visited[i])
			dfs(road, visited, i);
	}
}

void visit(double road[][MAX_POINT], int v)
{
	double average = 0.0;
	int arc = 0;
	int i;
	for (i = 1; i < MAX_POINT; i++) {
		average += road[v][i];
		if (road[v][i] > 0.0001)
			arc++;
	}
	average /= arc;
	printf ("%d, %.4f\n", v, average);
}

void bfs_traverse(double road[][MAX_POINT])
{
	int visited[MAX_POINT];
	int i;
	for (i = 1; i < MAX_POINT; i++)
		visited[i] = 0;
	struct queueLK *hq;
	initQueue(hq);
	for (i = 1; i < MAX_POINT; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			visit(road, i);
			enQueue(hq, i);
			while (!emptyQueue(hq)) {
				int u = outQueue(hq);
				int j;
				for (j = 1; j < MAX_POINT; j++) {
					if (road[u][j] > 0.0001 && !visited[j]) {
						visited[j] = 1;
						visit(road, j);
						enQueue(hq, j);
					}
				}
			}
		}
	}
	clearQueue(hq);
}

int main()
{
	FILE *fp = fopen("hw12p.txt", "r");
	Point *point = (Point *) malloc(MAX_POINT * sizeof(Point));
	int junk;
	double x, y;
	int i;
	for (i = 1; i < MAX_POINT; i++) {
		fscanf(fp, "%d%lf%lf", &junk, &x, &y);
		point[i].x = x;
		point[i].y = y;
	}
	fclose(fp);

	double road[MAX_POINT][MAX_POINT];
	FILE *fr = fopen("hw12r.txt", "r");
	int p1, p2;
	for (i = 0; i < 928; i++) {
		fscanf(fr, "%d %d", &p1, &p2);
		road[p1][p2] = sqrt((point[p1].x - point[p2].x) * (point[p1].x - point[p2].x)
							+ (point[p1].y - point[p2].y) * (point[p1].y - point[p2].y));
		road[p2][p1] = road[p1][p2];
	}
	dfs_traverse(road);
	//bfs_traverse(road);
	fclose(fr);
	free(point);
	return 0;
}
