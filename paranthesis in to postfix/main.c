#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////////////////////////
struct node{
char data;
struct node *next;
} ;

///////////////////////////////////////////////////////////////////////////////////////////
char pop( struct node **ptop);
void infix_to_postfix(char *a );
void push(char n , struct node **ptop);

/////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    char s[10];
    printf(("enter the expresssion:\n\n"));
    scanf("%s",s);
    infix_to_postfix_2(s);
    return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
void infix_to_postfix_2(char a[] ){
  char c[10]="";
  int i=0,k=0;
  struct node *top=NULL;
while (a[i]!='\0'){
if((a[i]=='+')||(a[i]=='-')){
            char temp=pop(&top);
            if(temp=='*'){
                c[k++]=temp;
                push(a[i],&top);
            }
            else{
                if(temp!='\0')
                push(temp,&top);
                push(a[i],&top);
            }
    }
else if((a[i]=='*')||(a[i]=='/')||(a[i]=='%')){
            if(((a[i]=='/')||(a[i]=='%'))&&a[i+1]!='('){
            c[k++]=a[i+1];
            c[k++]=a[i];
            i++;
        }
        else
            push(a[i],&top);
        }
else if(a[i]=='(')
            push(a[i],&top);
else if(a[i]==')')
{   char b=pop(&top);
    while(b!='(')
        {
       c[k++]=b;
       b=pop(&top);
        }
}
 else
     c[k++]=a[i];
i++;
}
while(top!=NULL){
    c[k++]=pop(&top);
}
c[k]='\0';
printf("\nthe post fix expression is :\n%s\n",c);
}

 ////////////////////////////////////////////////////////////////////////////////////////////
 void push(char n , struct node **ptop){
struct node *temp=malloc(sizeof(struct node));
temp->data=n;
if ((*ptop)==NULL){
    temp->next=NULL;
    *ptop=temp;
  //  printf("%c is pushed in\n\n",n);
}
else{
    temp->next=*ptop;
    *ptop=temp;
   //  printf("%c is pushed in\n\n",n);
}

}

//////////////////////////////////////////////////////////////////////////////////////////////
char pop( struct node **ptop){
struct node *q=*ptop;
if (q=='\0'){
   return  '\0';
}
        *ptop=q->next;
        char n=q->data;
         free(q);
         return n;
}

//<<<<<<<<<<<<<<<<<<<<<<<<<<END>>>>>>>>>>>>>>>>>>>>>>//
