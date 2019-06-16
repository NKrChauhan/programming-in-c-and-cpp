#include <stdio.h>
#include <stdlib.h>

struct node {
int data;
struct node *next;
};
int main()
{
    struct node *top=NULL;
    push(5,&top);
    push(6,&top);
    printf("%d is popped out\n\n", pop(&top));
    printf("%d is popped out\n\n", pop(&top));
    printf("%d is popped out\n\n", pop(&top));
    return 0;
}



void push(int n , struct node **ptop){
struct node *temp=malloc(sizeof(struct node));
temp->data=n;
if ((*ptop)==NULL){
    temp->next=NULL;
    *ptop=temp;
    printf("%d is pushed out\n",n);
}
else{
    temp->next=*ptop;
    *ptop=temp;
     printf("%d is pushed out\n",n);
}

}



int pop( struct node **ptop){
struct node *q=*ptop;
if (q==NULL){
   return 0;
}
        int n;
        *ptop=q->next;
        n=q->data;
         free(q);
         return n;
}
