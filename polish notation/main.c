#include <stdio.h>
#include <stdlib.h>

struct node {
char data;
struct node *next;
};


int main()
{
    printf("Hello world!\n");
    char  s[7];
    scanf("%s",s);
    printf("%s is %d",s,isvalid(s));
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
int  isvalid(char *c){
    int i=0;
    struct node *top=NULL;
while(c[i]!='\0'){
if(c[i]=='(')
    push(c[i],&top);
else
    {
        if(top==NULL)
            return 0;
        else {
                if(top->data=='(')
                  pop(&top);
             }
    }
    i++;
}
if(top==NULL)
    return 1;
else
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
void push(char n , struct node **ptop){
struct node *temp=malloc(sizeof(struct node));
temp->data=n;
if ((*ptop)==NULL){
    temp->next=NULL;
    *ptop=temp;
    printf("%c is pushed in\n",n);
}
else{
    temp->next=*ptop;
    *ptop=temp;
     printf("%c is pushed in\n",n);
}

}

//////////////////////////////////////////////////////////////////////////////////////////////
void pop( struct node **ptop){
struct node *q=*ptop;
if (q==NULL){
   return ;
}
        *ptop=q->next;
         free(q);
         return ;
}
