//
//  bst.h
//  Delete_bst
//
//  Created by Arrow on 7/15/18.
//  Copyright © 2018 Arrow. All rights reserved.
//

#ifndef bst_h
#define bst_h

typedef struct node {
    struct node* left;
    int key;
    struct node* right;
}node_t;

typedef struct tree {
    node_t* root;
}tree_t;

void init_tree(tree_t*);
void insert_tree(tree_t*, int);
void inorder(const tree_t*);
void delete(tree_t*, int);
void delete_min(tree_t*);
void delete_max(tree_t*);
int count_nodes(const tree_t*);
int count_leaves(const tree_t*);

#endif
