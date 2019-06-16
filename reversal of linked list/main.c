#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
int main(){
    printf("Hello world!\n");
    return 0;
}

void reverse(struct node **p){
    struct node *q,*r,*s;
    q=*p;
    s=q->next;
    while(s!=NULL)
    {
        r=s;
        s=s->next;
        r->next=q;
        q=r;
    }
    (*p)->next=NULL;
     *p=q;
}

void sort(struct node *p){
    struct node *fresh=NULL,*temp=p,*node;
    int max=-9999;
   while(p!=NULL){
    while(temp->next!=NULL){
         if(temp->data > max)
           max=temp->data;
}
    delete_node(p,max);
    node=(struct node *)malloc(sizeof(struct node));
    node->data=max;
    if (fresh == NULL)
        {
            fresh=node;
            node->next=NULL;
        }
    else
    {
        node->next=fresh;
        fresh=node;
    }
   }
     p=fresh;
}

void delete_node(struct node **p, int n){
   struct node *temp;
   temp=(*p);
   if(*p==NULL){
    printf("empty list");
    free(temp);
    return;
   }
   else if((*p)->data=n){
    (*p)=(*p)->next;
    free(temp);
    return;
   }
   else {
    while(temp->next!=NULL){
       if((temp->next)->data==n){
          struct node *q=temp->next;
          temp->next=(temp->next)->next;
          free(q);
          return;
    }
    else
    temp=temp->next;
    }
     printf("data not found");
     return;
   }
}

void insert(struct node **p,int n){
        struct node *temp;
       struct node *nod=malloc(sizeof(struct node));
       nod->data=n;
       nod->next=NULL;
        if((*p)==NULL)                                                //inserting if heat not present
            (*p)=nod;
        else {      temp=*p;                                         //inserting in the last position
                   while(temp->next!=NULL)                   //traversing
                        temp=temp->next;
                  temp->next =nod;
             }
}
