#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 582
#define INFINIT 9999

typedef struct point {
    double x;
    double y;
} Point;

void dijkstra(double graph[][MAXSIZE], int s)
{
    int i;
    float distance[MAXSIZE];
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
                float temp = distance[current] + graph[current][i];
                if (temp < distance[i])
                    distance[i] = temp;
            }
        }
        if (current != s)
            visited[current] = 1;
        int smallest = INFINIT;
        int next;
        for (i = 0; i < MAXSIZE; i++) {
            if (visited[i] == 0 && distance[i] < smallest)
                next = i;
            smallest = distance[i];
        }
        if (smallest == INFINIT)
            break;
        current = next;
    }
	for (i = 0; i < MAXSIZE; i++)
		if (i != s && distance[i] < INFINIT)
			printf ("%d,%d,%.4f\n", s, i, distance[i]);
}

void floyd(double graph[][MAXSIZE])
{
    double distance[MAXSIZE][MAXSIZE];
    int u, v, w;
    int i;

    for (v = 0; v < MAXSIZE; v++)
        for (w = 0; w < MAXSIZE; w++)
            distance[v][w] = graph[v][w];

    for (u = 0; u < MAXSIZE; u++)
        for (v = 0; v < MAXSIZE; v++)
            for (w = 0; w < MAXSIZE; w++)
                if (distance[v][u]+distance[u][w] < distance[v][w])
                    distance[v][w] =  distance[v][u]+distance[u][w];
    for (v = 0; v < MAXSIZE; v++)
        for (w = v+1; w < MAXSIZE; w++)
            if (distance[v][w] < INFINIT)
                printf ("%d, %d, %f\n", v, w, distance[v][w]);

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
    for (i = 0; i < MAXSIZE; i++)
    	dijkstra(graph, i);
    //floyd(graph);
    fclose(fr);
    fclose(fp);
    free(point);

    return 0;
}