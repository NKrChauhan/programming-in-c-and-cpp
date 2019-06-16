#include <stdio.h>
#include <stdlib.h>
///////////////////////////////////////////////////////////////////////////////////////////////////
struct node{
int data;
struct node *left;
struct node *right;
};

///////////////////////////////////////////////////////////////////////////////////////////////////
void Insert(int ,struct node *);
void Delete(int ,struct node **);
int Min(struct node *);
int Max(struct node *);
void inorder(struct node *root);
void preorder(struct node *root);

//////////////////////////////////////////////////////////////////////////////////////////////////
int main(){
    printf("Hello world!\n");
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void Insert(int data,struct node *phead){
if(phead==NULL){
       struct node *New=(struct node *)malloc(sizeof(struct node));
        New->data=data;
        New->left=NULL;
        New->right=NULL;
        phead=New ;
        return;

}
else if((phead)->data>data)
    {
    Insert(data,&(phead)->left);
    }
else if((phead)->data<data)
   {
    Insert(data,&(phead)->right);
   }}

//////////////////////////////////////////////////////////////////////////////////////////////////
void Delete(int data,struct node **phead) {
if((*phead)==NULL) {
printf("either data not found or tree is empty");
return;
}
else if((*phead)->data>data) {
    Delete(data,&(*phead)->left);
}
else if((*phead)->data<data) {
    Delete(data,&(*phead)->right);
}
else {
    if((*phead)->left==NULL && (*phead)->right==NULL)
    {   struct node *temp=*phead;
         *phead=NULL;
        free(temp);
    }
    else if((*phead)->left!=NULL && (*phead)->right!=NULL) {
        data=Min(*phead);
        (*phead)->data=data;
        Delete(data,phead);
    }
    else {
        if((*phead)->left==NULL)  {
         struct node *temp=*phead;
         *phead=(*phead)->right;
         free(temp);
        }
        else  {
         data=Max(*phead);
         (*phead)->data=data;
         Delete(data,phead);
        }
}}}

//////////////////////////////////////////////////////////////////////////////////////////////////
int Min(struct node *root) {
while(root->left!=NULL){
    root=root->left;
}
return (root->data);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
int Max(struct node *root){
while(root->right!=NULL){
    root=root->right;
}
return (root->data);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void inorder(struct node *root){
if(root!=NULL){
inorder(root->left);
printf("%d\n",root->data);
inorder(root->right);
}
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void preorder(struct node *root){
    if(root!=NULL){
printf("%d\n",root->data);
inorder(root->left);
inorder(root->right);
}
}

//////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////
