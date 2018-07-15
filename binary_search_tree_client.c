//
//  main.c
//  Delete_bst
//
//  Created by Arrow on 7/15/18.
//  Copyright © 2018 Arrow. All rights reserved.
//

#include <stdio.h>
#include "bst.h"

int main() {
    tree_t t;
    init_tree(&t);
    int a[] = {40, 20, 60, 70, 30, 10, 50, 15};
    int n = 8;
    for(int i = 0; i < n; ++i)
    {
        insert_tree(&t, a[i]);
    }
    inorder(&t); printf("\n");
    printf("nodes: %d\n",count_nodes(&t));
    printf("nodes: %d\n",count_leaves(&t));
    delete_min(&t);
    inorder(&t); printf("\n");
    delete_max(&t);
    inorder(&t); printf("\n");
    delete(&t,30);
    inorder(&t); printf("\n");
    return 0;
}
