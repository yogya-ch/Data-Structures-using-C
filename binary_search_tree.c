//
//  bst.c
//  Delete_bst
//
//  Created by Arrow on 7/15/18.
//  Copyright © 2018 Arrow. All rights reserved.
//

#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

void init_tree(tree_t* ptr_tree) {
    ptr_tree->root = NULL;
}
node_t* insert_r(node_t* root, node_t* temp)
{
    if(root == NULL) {
        root = temp;
    }
    else if(temp->key < root->key) {
        root->left = insert_r(root->left, temp);
    }
    else {
        root->right = insert_r(root->right, temp);
    }
    return root;
}

void insert_tree(tree_t* ptr_tree, int key) {
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->key = key; temp->left = temp->right = NULL;
    ptr_tree->root = insert_r(ptr_tree->root, temp);
}

void inorder_r(const node_t* temp) {
    if(temp != NULL) {
        inorder_r(temp->left);
        printf("%d ", temp->key);
        inorder_r(temp->right);
    }
}

void inorder(const tree_t* ptr_tree) {
    inorder_r(ptr_tree->root);
}


void delete_min(tree_t* ptr_tree){
    node_t* temp=ptr_tree->root;
    node_t* parent=ptr_tree->root;
    while(temp->left != NULL){
        parent=temp;
        temp=temp->left;
    }
    parent->left=temp->right;
    free(temp);
}

void delete_max(tree_t* ptr_tree){
    node_t* temp=ptr_tree->root;
    node_t* parent=ptr_tree->root;
    while(temp->right != NULL){
        parent=temp;
        temp=temp->right;
    }
    parent->right=temp->left;
    free(temp);
}

void delete_r(node_t* root, int val, node_t* parent){
    if(root->left==NULL && root->right==NULL) {
        if (parent->left == root) {
            parent->left=NULL;
        }
        else if (parent->right == root) {
            parent->right=NULL;
        }
        free(root);
    }
    else if(root->left->key > root->right->key) {
        root->key=root->left->key;
        delete_r(root->left, val, root);
    }
    else {
        root->key=root->right->key;
        delete_r(root->right, val, root);
    }
}

void find_r(node_t* root,int val,node_t* parent){
    if(val < root->key) {
        find_r(root->left, val,root);
    }
    else if(val > root->key) {
        find_r(root->right, val,root);
    }
    else if(val == root->key) {
        delete_r(root, val, parent);
    }
}

void delete(tree_t* ptr_tree,int val){
    node_t* parent=NULL;
    if(ptr_tree->root==NULL){
        ;
    }
    else{
        find_r(ptr_tree->root,val,parent);
    }
}

int count_nodes_r(const node_t *temp) {
    if(temp == NULL) {
        return 0;
    }
    else {
        return 1 + count_nodes_r(temp->left) + count_nodes_r(temp->right);
    }
}

int count_nodes(const tree_t* ptr_tree) {
    return count_nodes_r(ptr_tree->root);
}

int count_leaves_r(const node_t *temp) {
    if(temp == NULL) {
        return 0;
    }
    else if(temp->left == NULL && temp->right == NULL) {
        return 1;
    }
    else {
        return count_leaves_r(temp->left) + count_leaves_r(temp->right);
    }
}

int count_leaves(const tree_t* ptr_tree) {
    return count_leaves_r(ptr_tree->root);
}
