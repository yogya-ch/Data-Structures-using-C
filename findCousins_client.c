//
//  main.c
//  findCousins
//


#include <stdio.h>
#include "findCousins.h"


int main() {
    tree_t t;
    init(&t);
    int a[] = {40, 20, 60, 70, 10, 30};
    int n = 6;
    for(int i = 0; i < n; ++i)
    {
        insert(&t, a[i]);
    }
    inorder(&t);
    printf("\n");
    findCousins(&t,10);
    printf("\n");
    findSiblings(&t,10);
    return 0;
}
