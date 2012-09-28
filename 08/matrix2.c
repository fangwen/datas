#include <stdio.h>
#include <stdlib.h>

typedef struct olnode {
    int i, j;
    int e;
    struct olnode *right, *down;
} *Olink;

typedef struct {
    Olink *rhead, *chead;
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
    mat->rhead = (Olink *)malloc(m*sizeof(Olink));
    mat->chead = (Olink *)malloc(n*sizeof(Olink));
    int s;
    for (s = 0; s < mat->rows; s++)
        mat->rhead[s] = NULL;
    for (s = 0; s < mat->cols; s++)
        mat->chead[s] = NULL;
    int k;
    int i, j, e;
    for (k = 0; k < mat->terms; k++) {
        scanf("%d %d %d", &i, &j, &e);
        struct olnode *p = (struct olnode *)malloc(sizeof(struct olnode));
        p->i = i;
        p->j = j;
        p->e = e;
        if(mat->rhead[i] == NULL || mat->rhead[i]->j > j) {
            p->right = mat->rhead[i];
            mat->rhead[i] = p;
        } else {
            struct olnode *q;
            for (q = mat->rhead[i]; (q != NULL) && (q->j < j); q = q->right) {
                p->right = q->right;
                q->right = p;
            }
        }
        if(mat->chead[j] == NULL || mat->chead[j]->i > i) {
            p->down = mat->chead[j];
            mat->chead[j] = p;
        } else {
            struct olnode *q;
            for (q = mat->chead[j]; (q != NULL) && (q->i < i); q = q->down) {
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
    struct olnode *q;
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
    struct olnode *q;
    q = (&mat)->rhead[1];
    printf ("%d\n", q->e);
    q = q->right;
    printf ("%d\n", q->e);
    return 0;
}
