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

void creat_matrix(Crosslist * mat)
{
    int m, n, t;
    printf("%s\n", "Please input the rows, cols and terms of the matrix:");
    scanf("%d %d %d", &m, &n, &t);
    printf("%s\n", "Please input the elements, in triple data form:");
    mat->rows = m;
    mat->cols = n;
    mat->terms = t;
    mat->rhead = (Link *) malloc((m + 1) * sizeof(Link));
    mat->chead = (Link *) malloc((n + 1) * sizeof(Link));
    int x;
    for (x = 0; x < mat->rows + 1; x++)
	mat->rhead[x] = NULL;
    for (x = 0; x < mat->cols + 1; x++)
	mat->chead[x] = NULL;

    int term;
    int i, j, e;
    for (term = 0; term < mat->terms; term++) {
	scanf("%d %d %d", &i, &j, &e);
	struct node *p = (struct node *) malloc(sizeof(struct node));
	p->i = i;
	p->j = j;
	p->e = e;
	if (mat->rhead[i] == NULL || mat->rhead[i]->j > j) {
	    p->right = mat->rhead[i];
	    mat->rhead[i] = p;
	} else {
	    struct node *q;
	    for (q = mat->rhead[i]; q->right != NULL && q->right->j < j;
		 q = q->right);
	    p->right = q->right;
	    q->right = p;
	}
	if (mat->chead[j] == NULL || mat->chead[j]->i > i) {
	    p->down = mat->chead[j];
	    mat->chead[j] = p;
	} else {
	    struct node *q;
	    for (q = mat->chead[j]; q->down != NULL && q->right->i < i;
		 q = q->down);
	    p->down = q->down;
	    q->down = p;
	}
    }
}

void insert(Crosslist * mat, struct node *p)
{
    int i = p->i;
    int j = p->j;
    int e = p->e;
    if (mat->rhead[i] == NULL || mat->rhead[i]->j > j) {
	p->right = mat->rhead[i];
	mat->rhead[i] = p;
    } else {
	struct node *q;
	for (q = mat->rhead[i]; q->right != NULL && q->right->j < j;
	     q = q->right);
	p->right = q->right;
	q->right = p;
    }
    if (mat->chead[j] == NULL || mat->chead[j]->i > i) {
	p->down = mat->chead[j];
	mat->chead[j] = p;
    } else {
	struct node *q;
	for (q = mat->chead[j]; q->down != NULL && q->down->i < i;
	     q = q->down);
	p->down = q->down;
	q->down = p;
    }
}

void add_matrix(Crosslist * mat1, Crosslist * mat2, Crosslist * mat3)
{
    int m = mat1->rows;
    int n = mat1->cols;
    mat3->rows = m;
    mat3->cols = n;
    mat3->rhead = (Link *) malloc((m + 1) * sizeof(Link));
    mat3->chead = (Link *) malloc((n + 1) * sizeof(Link));
    int x;
    for (x = 0; x < mat3->rows + 1; x++)
	mat3->rhead[x] = NULL;
    for (x = 0; x < mat3->cols + 1; x++)
	mat3->chead[x] = NULL;
    struct node *p1, *p2;
    int i;
    for (i = 1; i < mat1->rows + 1; i++) {
	p1 = mat1->rhead[i];
	p2 = mat2->rhead[i];
	while (p1 != NULL && p2 != NULL) {
	    if (p1->j < p2->j) {
		struct node *temp =
		    (struct node *) malloc(sizeof(struct node));
		*temp = *p1;
		insert(mat3, temp);
		p1 = p1->right;
	    } else if (p1->j > p2->j) {
		struct node *temp =
		    (struct node *) malloc(sizeof(struct node));
		*temp = *p2;
		insert(mat3, temp);
		p2 = p2->right;
	    } else if (p1->e + p2->e != 0) {
		struct node *temp =
		    (struct node *) malloc(sizeof(struct node));
		temp->i = p1->i;
		temp->j = p1->j;
		temp->e = p1->e + p2->e;
		insert(mat3, temp);
		p1 = p1->right;
		p2 = p2->right;
	    } else {
		p1 = p1->right;
		p2 = p2->right;
	    }
	}
	while (p1 != NULL) {
	    struct node *temp =
		(struct node *) malloc(sizeof(struct node));
	    *temp = *p1;
	    insert(mat3, temp);
	    p1 = p1->right;
	}
	while (p2 != NULL) {
	    struct node *temp =
		(struct node *) malloc(sizeof(struct node));
	    *temp = *p2;
	    insert(mat3, temp);
	    p2 = p2->right;
	}
    }
}

void print_matrix(Crosslist * mat)
{
    printf("%s\n", "The matrix is:");
    int i;
    struct node *q;
    for (i = 1; i < mat->rows + 1; i++) {
	for (q = mat->rhead[i]; q != NULL; q = q->right)
	    printf("%-3d%-3d%-3d\n", q->i, q->j, q->e);
    }
}

int main()
{
    Crosslist mat1, mat2, mat3;
    creat_matrix(&mat1);
    print_matrix(&mat1);
    creat_matrix(&mat2);
    print_matrix(&mat2);
    add_matrix(&mat1, &mat2, &mat3);
    print_matrix(&mat3);
    return 0;
}
