//
//  main.c
//  even_odd_linked_list
//
//  Created by Arrow on 7/1/18.
//  Copyright © 2018 Arrow. All rights reserved.
//

#include <stdio.h>
#include "odd_eve.h"

int main() {
    int a[5][5]={{4,2,7,3,1},{2,4,6,9,1},{7,3,5,1,2},{6,5,4,3,2},{2,3,4,5,7}};
    list_t ptr_list;
    
    for(int i=0;i<5;i++){
        init(&ptr_list);
        for (int j=0;j<5;j++) {
            insert(&ptr_list, a[i][j]);
        }
        display(&ptr_list);
        moveEven2front(&ptr_list);
        display(&ptr_list);
        printf("\n");
    }

    return 0;
}
