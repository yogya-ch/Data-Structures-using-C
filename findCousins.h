//
//  findCousins.h


#ifndef findCousins_h
#define findCousins_h

typedef struct node{
    struct node* left;
    int data;
    struct node* right;
}node_t;

typedef struct tree{
    node_t* root;
}tree_t;

void init(tree_t*);
void insert(tree_t*,int);
void inorder(const tree_t*);
void findCousins(const tree_t*,int);
void findSiblings(const tree_t*,int);

#endif /* findCousins_h */
