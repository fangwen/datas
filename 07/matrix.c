#include <stdio.h>

typedef struct {
    int i, j;
    int e;
} triple;

typedef struct {
    triple data[100];
    int rows, cols, terms;
} matrix;

void get_matrix(matrix * mat)
{
    printf("%s\n", "Please input the rows and cols:");
    scanf("%d %d", &mat->rows, &mat->cols);
    printf("%s\n", "Please input the matrix element:");
    int p = 0;
    int temp;
    int i;
    for (i = 0; i < mat->rows; i++) {
	int j;
	for (j = 0; j < mat->cols; j++) {
	    scanf("%d", &temp);
	    if (temp) {
		mat->data[p].i = i;
		mat->data[p].j = j;
		mat->data[p].e = temp;
		p++;
	    }
	}
    }
    mat->terms = p;
}

void print_matrix(matrix * mat)
{
    printf("%s\n", "The matrix is:");
    int i;
    int p = 0;
    for (i = 0; i < mat->rows; i++) {
	int j;
	for (j = 0; j < mat->cols; j++) {
	    if (p < mat->terms && mat->data[p].i == i
		&& mat->data[p].j == j) {
		printf("%-3d", mat->data[p].e);
		p++;
	    } else
		printf("%-3d", 0);
	}
	printf("\n");
    }
}

void trans(matrix * mat1, matrix * mat2)
{
    mat2->rows = mat1->cols;
    mat2->cols = mat1->rows;
    mat2->terms = mat1->terms;
    int num[mat2->cols];
    int cpot[mat2->cols];
    if (mat2->terms > 0) {
	int i;
	for (i = 0; i < mat1->cols; i++)
	    num[i] = 0;
	for (i = 0; i < mat1->terms; i++)
	    num[mat1->data[i].j]++;
	cpot[0] = 0;
	for (i = 1; i < mat1->cols; i++)
	    cpot[i] = cpot[i - 1] + num[i - 1];
	int p, q;
	int col;
	for (p = 0; p < mat1->terms; p++) {
	    col = mat1->data[p].j;
	    q = cpot[col];
	    mat2->data[q].i = mat1->data[p].j;
	    mat2->data[q].j = mat1->data[p].i;
	    mat2->data[q].e = mat1->data[p].e;
	    cpot[col]++;
	}
    }
}

int find(matrix * mat, int i, int j)
{
    int k;
    for (k = 0; k < mat->terms; k++) {
	if (mat->data[k].i == i && mat->data[k].j == j)
	    return mat->data[k].e;
	else if (k == mat->terms - 1)
	    return 0;
    }
}

void multi(matrix * mat1, matrix * mat2, matrix * mat3)
{
    int n = 0;
    int temp;
    int i;
    for (i = 0; i < mat1->rows; i++) {
	int j;
	for (j = 0; j < mat2->cols; j++) {
	    int k;
	    temp = 0;
	    for (k = 0; k < mat1->cols; k++)
		temp += find(mat1, i, k) * find(mat2, k, j);
	    if (temp) {
		mat3->data[n].i = i;
		mat3->data[n].j = j;
		mat3->data[n].e = temp;
		n++;
	    }
	}
    }
    mat3->rows = mat1->rows;
    mat3->cols = mat2->cols;
    mat3->terms = n;
}

int main()
{
    matrix mat1, mat2, mat3;
    get_matrix(&mat1);
    print_matrix(&mat1);
    trans(&mat1, &mat2);
    print_matrix(&mat2);
    multi(&mat1, &mat2, &mat3);
    print_matrix(&mat3);
    return 0;
}
