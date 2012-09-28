#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 582
#define INFINIT 9999

typedef struct point {
    double x;
    double y;
} Point;

void print_dij(int path_dij[MAXSIZE], int node)
{
	int before = path_dij[node];
	if (before > -1) {
		print_dij(path_dij, before);
		printf ("%d,", node);
	}
	else
		return;
}

void print_flo(int path[MAXSIZE][MAXSIZE], int v, int w)
{
	int before = path[v][w];
	if (before > -1) {
		print_flo(path, v, before);
		printf("%d,", w);
	}
	else
		return;
}

void dijkstra(double graph[][MAXSIZE], int s, int path[MAXSIZE])
{
    int i;
	for (i = 0; i < MAXSIZE; i++)
		path[i] = -1;
    double distance[MAXSIZE];
    distance[s] = 0.0;
    for (i = 0; i < MAXSIZE; i++) {
        if (i != s)
            distance[i] = INFINIT;
    }
    int visited[MAXSIZE];
    visited[s] = 1;
    for (i = 0; i < MAXSIZE; i++) {
        if (i != s)
            visited[i] = 0;
    }
    int current = s;
    while (1) {
        for (i = 0; i < MAXSIZE; i++) {
            if (visited[i] == 0 && i != current && graph[current][i] < INFINIT) {
                double temp = distance[current] + graph[current][i];
                if (temp < distance[i]) {
                    distance[i] = temp;
					path[i] = current;
				}
			}
        }
        if (current != s)
            visited[current] = 1;
        int smallest = INFINIT;
        int next;
        for (i = 0; i < MAXSIZE; i++) {
            if (visited[i] == 0 && distance[i] < smallest) {
                next = i;
				smallest = distance[i];
			}
        }
        if (smallest >= INFINIT)
            break;
        current = next;
    }
	for (i = 0; i < MAXSIZE; i++)
		if (i != s && distance[i] < INFINIT) {
			printf ("%d,%d,%.4f,", s, i, distance[i]);
			print_dij(path, i);
			printf ("\n");
		}
}

void floyd(double graph[][MAXSIZE])
{
    double distance[MAXSIZE][MAXSIZE];
	int path[MAXSIZE][MAXSIZE];
    int u, v, w;
    int i;
	for (v = 0; v < MAXSIZE; v++)
		for (w = 0; w < MAXSIZE; w++)
			path[v][w] = -1;
    for (v = 0; v < MAXSIZE; v++)
        for (w = 0; w < MAXSIZE; w++) {
            distance[v][w] = graph[v][w];
			if (distance[v][w] < INFINIT && v != w)
				path[v][w] = v;
		}

    for (u = 0; u < MAXSIZE; u++)
        for (v = 0; v < MAXSIZE; v++)
            for (w = 0; w < MAXSIZE; w++)
                if (distance[v][u]+distance[u][w] < distance[v][w]) {
                    distance[v][w] =  distance[v][u]+distance[u][w];
					path[v][w] = u;
				}

	for (v = 0; v < MAXSIZE; v++)
        for (w = 0; w < MAXSIZE; w++)
            if (v != w && distance[v][w] < INFINIT) {
				printf ("%d,%d,%.4f,", v, w, distance[v][w]);
				print_flo(path, v, w);
				printf ("\n");
			}
}

int main()
{
    Point *point = (Point *) malloc(MAXSIZE * sizeof(Point));
    FILE *fp = fopen("hw12p.txt", "r");
    FILE *fr = fopen("hw12r.txt", "r");

    int junk;
    double x, y;
    int i;
    for (i = 0; i < MAXSIZE; i++) {
        fscanf(fp, "%d%lf%lf", &junk, &x, &y);
        point[i].x = x;
        point[i].y = y;
    }

    double graph[MAXSIZE][MAXSIZE];
    int j;
    for (i = 0; i < MAXSIZE; i++)
        for (j = 0; j < MAXSIZE; j++) {
            if ( i != j)
                graph[i][j] = INFINIT;
            else
                graph[i][j] = 0.0;
        }
    int p1, p2;
    for (i = 0; i < 928; i++) {
        fscanf(fr, "%d%d", &p1, &p2);
        p1 -= 1;
        p2 -= 1;
        graph[p1][p2] = sqrt((point[p1].x - point[p2].x) * (point[p1].x - point[p2].x)
                + (point[p1].y - point[p2].y) * (point[p1].y - point[p2].y));
    }

    floyd(graph);
	//int path_dij[MAXSIZE];
	//for (i = 0; i < MAXSIZE; i++) {
    //	dijkstra(graph, i, path_dij);
	//}
	fclose(fr);
    fclose(fp);
    free(point);

    return 0;
}
