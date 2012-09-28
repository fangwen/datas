#define MAX_LENGTH 100

typedef struct node {
    float coef;
    int expn;
    int next;
}node;

int list_length(node list[]);
void list_insert(node list[], int i, float coef, int expn);
void init_list(node list[]);
void list_delete(node list[], int i);
void print_list(node list[]);
void add(node list[], node list2[], node result[]);
void print2(node list[]);
void arrange(node list[]);
