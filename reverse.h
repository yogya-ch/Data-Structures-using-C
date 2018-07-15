typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct list{
	node_t* head;
}list_t;

void init_list(list_t*);
void insert(list_t*,int,int);
void display(list_t*);
int length(list_t*);
void delete(list_t*);
void reverse(list_t*);
