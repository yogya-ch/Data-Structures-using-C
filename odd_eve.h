//Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.

#ifndef odd_eve_h
#define odd_eve_h

typedef struct node{
    int data;
    struct node* next;
}node_t;

typedef struct list{
    node_t* head;
}list_t;

void init(list_t*);
void insert(list_t*,int);
void moveEven2front(list_t*);
void display(const list_t*);

#endif /* odd_eve_h */
