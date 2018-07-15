#include<stdio.h>
#include"reverse.h"

int main(){
	int n;
 	int pos;
	int data;
	list_t ptr_list;
 	init_list(&ptr_list);
	printf("MENU:\n1) Insert in ith pos\n2) Delete at the end\n3) Reverse\n4) Display \n0) Exit\n");
	scanf("%d",&n);
	while(n){
		switch(n){
			case 1:
                printf("Give position: ");
				scanf("%d",&pos);
                printf("Give data: ");
				scanf("%d",&data);
				insert(&ptr_list,data,pos);
				break;
			case 2:
				delete(&ptr_list);
				break;
     			 case 3:
  				reverse(&ptr_list);
  				break;
     			case 4:
       				display(&ptr_list);
        			break;
      			default:
       				printf("Not in menu\n");
        			break;
		}
		printf("MENU:\n1) Insert in ith pos\n2) Delete at the end\n3) Reverse\n4) Display \n0) Exit\n");
		scanf("%d",&n);
	}
}
