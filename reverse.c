#include "reverse.h"
#include <stdio.h>
#include <stdlib.h>

void display(list_t* ptr_list){
 	node_t* present=ptr_list->head;
    if(present==NULL) printf("Empty list\n");
	while(present !=NULL){
		printf("%d  ",present->data);
		present=present->next;
	}
	printf("\n");
}

void init_list(list_t* ptr_list){
	ptr_list->head=NULL;
}

void insert(list_t* ptr_list,int data,int pos){
	node_t* new=(node_t*)malloc(sizeof(node_t));
	new->data=data;
	node_t* prev=NULL;
  	node_t* present=ptr_list->head;
  	int len;
  	len=length(ptr_list);
  	if(pos<0) printf("Invalid position\n");
    else if(pos>len) printf("The position is beyond the length of the list\n");
  	else{
  		if(ptr_list->head==NULL || pos==0){
  			ptr_list->head=new;
  			new->next=present;
  		}
  		else{
			for(int i=0;i<pos;i++){
				prev=present;
				present=present->next;
			}
			prev->next=new;
			new->next=present;
		}
	}
	
}

int length(list_t* ptr_list){
	int count=0;
	node_t* present=ptr_list->head;
	while(present !=NULL){
		present=present->next;
		count+=1;
	}
	return count;
}

void  delete(list_t* ptr_list){
	node_t* present=ptr_list->head;
	node_t* prev=NULL;
	if(present==NULL){
		printf("No element to delete\n");
	}
	else if(present->next==NULL){
        printf("Delete last element\n");
		ptr_list->head=NULL;
        free(present);
	}
	else{
		while(present->next!=NULL){
		   	prev=present;
		   	present=present->next;
	   	}
     		prev->next=NULL;
            free(present);
     	}
  	
}

void reverse(list_t* ptr_list){
    node_t* prev=NULL;
    node_t* present=ptr_list->head;
    node_t* temp=ptr_list->head;
    if(present==NULL){
        printf("No list\n");
    }
    else if(present->next==NULL){
        printf("Single element in list\n");
    }
    else{
        temp=present->next;
        while(temp!=NULL){
            prev=present;
            present=temp;
            temp=present->next;
            present->next=prev;
        }
        prev=ptr_list->head;
        prev->next=NULL;
        ptr_list->head=present;
    }
}
