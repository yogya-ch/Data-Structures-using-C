//
//  odd_eve.c
//  even_odd_linked_list
//
//  Created by Arrow on 7/1/18.
//  Copyright © 2018 Arrow. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "odd_eve.h"

void init(list_t* ptr){
    ptr->head=NULL;
}

void insert(list_t* ptr,int data){
    node_t* temp;
    node_t* current;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->data = data;
    temp->next = NULL;
    current=ptr->head;
    if(ptr->head == NULL)
    {
        ptr->head = temp;
        temp->next = NULL;
    }
    else{
        while( current->next!= NULL){
            current=current->next;
        }
        current->next=temp;
    }
}

void moveEven2front(list_t* ptr){
    node_t* current=ptr->head;
    node_t* prev=NULL;
    node_t* firstOdd = ptr->head;
    node_t* preFirstOdd = NULL;
    
    node_t* tmp = NULL;
    if(ptr->head!=NULL){
        while((firstOdd->data%2)==0){
            preFirstOdd=firstOdd;
            firstOdd=firstOdd->next;
        }
        current = firstOdd;
        while(current!=NULL) {
            if((current->data%2)==0 && (prev!=NULL)) {
                prev->next=current->next;
                tmp=current->next;
                current->next=firstOdd;
                if(firstOdd==ptr->head) {
                    ptr->head=current;
                    preFirstOdd=current;
                } else {
                    preFirstOdd->next = current;
                    preFirstOdd = current;
                }
                current = tmp;
            } else {
                prev=current;
                current=current->next;
            }
        }
    }
}

void display(const list_t* ptr){
    node_t* current=ptr->head;
    if(ptr->head==NULL) printf("Empty List\n");
    while( current!= NULL){
        printf("%d, ",current->data);
        current=current->next;
    }
    printf("\n");
}
