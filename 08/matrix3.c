#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int i, j;
    int e;
    struct node *right, *down;
} *Link;

typedef struct {
    Link *rhead, *chead;
    int rows, cols, terms;
} Crosslist;

void creat_matrix(Crosslist *mat)
{
    int m, n, t;
    printf ("%s\n", "Please input the rows, cols and terms of the matrix:");
    scanf("%d %d %d", &m, &n, &t);
    printf ("%s\n", "Please input the elements, in triple data form:");
    mat->rows = m;
    mat->cols = n;
    mat->terms = t;
    mat->rhead = (Link *)malloc(m*sizeof(Link));
    mat->chead = (Link *)malloc(n*sizeof(Link));
    int x;
    for (x = 0; x < mat->rows; x++)
        mat->rhead[x] = NULL;
    for (x = 0; x < mat->cols; x++)
        mat->chead[x] = NULL;
    int term;
    int i, j, e;
    for (term = 0; term < mat->terms; term++) {
        scanf("%d %d %d", &i, &j, &e);
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->i = i;
        p->j = j;
        p->e = e;
        if(mat->rhead[i] == NULL || mat->rhead[i]->j > j) {
            p->right = mat->rhead[i];
            mat->rhead[i] = p;
        } else {
            struct node *q;
            for (q = mat->rhead[i]; q != NULL && q->j < j; q = q->right) {
                p->right = q->right;
                q->right = p;
            }
        }
        if(mat->chead[j] == NULL || mat->chead[j]->i > i) {
            p->down = mat->chead[j];
            mat->chead[j] = p;
        } else {
            struct node *q;
            for (q = mat->chead[j]; q != NULL && q->i < i; q = q->down) {
                p->down = q->down;
                q->down = p;
            }
        }
    }
}

void print_matrix(Crosslist *mat)
{
    printf ("%s\n", "The matrix is:");
    int i;
    struct node *q;
    for (i = 0; i < mat->rows; i++) {
        for (q = mat->rhead[i]; q != NULL; q = q->right)
            printf ("%-3d%-3d%-3d\n", q->i, q->j, q->e);
    }
}

int main()
{
    Crosslist mat;
    creat_matrix(&mat);
    print_matrix(&mat);
    return 0;
}
