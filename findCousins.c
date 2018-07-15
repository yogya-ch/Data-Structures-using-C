//
//  findCousins.c

#include "findCousins.h"
#include <stdio.h>
#include <stdlib.h>

void init(tree_t* ptr_tree) {
    ptr_tree->root = NULL;
}
node_t* insert_r(node_t* root, node_t* temp) {
    if(root == NULL) {
        root = temp;
    } else if(temp->data < root->data) {
        root->left = insert_r(root->left, temp);
    } else {
        root->right = insert_r(root->right, temp);
    }
    return root;
}

void insert(tree_t* ptr_tree, int data) {
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data; temp->left = temp->right = NULL;
    ptr_tree->root = insert_r(ptr_tree->root, temp);
}


void inorder_r(const node_t* temp) {
    if(temp != NULL) {
        inorder_r(temp->left);
        printf("%d ", temp->data);
        inorder_r(temp->right);
    }
}

void inorder(const tree_t* ptr_tree) {
    inorder_r(ptr_tree->root);
}

int depth(node_t* temp, int val){
    if (temp==NULL){
        return 0;
    }
    else if(temp->data==val){
        return 1;
    }
    else if(temp->data > val){
        return 1+depth(temp->left, val);
    }
    else{
        return 1+depth(temp->right, val);
    }
}

int findSiblings_r(node_t* root,int val){
    if(root==NULL || root->left==NULL || root->right==NULL){
        return 0;
    }
    else if(root->left->data==val){
        return root->right->data;
    }
    else if(root->right->data==val){
        return root->left->data;
    }
    else if(val<root->data){
        return findSiblings_r(root->left,val);
    }
    else{
        return findSiblings_r(root->right,val);
    }
}

void findCousins_r(node_t* root,int val,int dep,int sib,int cur_dep){
    if(root==NULL){
        ;
    }
    else if(cur_dep<dep){
        findCousins_r(root->left,val,dep,sib,cur_dep+1);
        findCousins_r(root->right,val,dep,sib,cur_dep+1);
    }
    else if(cur_dep==dep && root->data!=val && root->data!=sib){
        printf("%d ",root->data);
    }
}

void findCousins(const tree_t* ptr_tree, int val){
    int dep=depth(ptr_tree->root,val);
    printf("%d\n",dep);
    int cur_dep=1;
    int sib=findSiblings_r(ptr_tree->root,val);
    findCousins_r(ptr_tree->root, val,dep,sib,cur_dep);
}

void findSiblings(const tree_t* ptr_tree, int val){
    printf("%d\n",findSiblings_r(ptr_tree->root,val));
}
