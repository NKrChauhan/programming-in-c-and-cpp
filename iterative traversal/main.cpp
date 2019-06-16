#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
}
void PreOrder(struct node *head){
    int i=0;
    vector<struct node *> s(1000);
    while(1){
        while(head){
            printf("%d\n",head->data);
            s[i++]=head;
            head=head->left;
        }
        if(i==0) break;
        head=s[i--];
        head=head->right;
    }
}
void Inorder(struct node *head){
    int i=0;
    vector<struct node *> s(1000);
    while(1){
        while(head){
            s[i++]=head;
            head=head->left;
        }
        if(i==0) break;
        head=s[i--];
        printf("%d\n",head->data);
        head=head->right;
    }
}
void Postorder(struct node *head){
    int i=0;
    vector<struct node *> s(1000);
    struct node *p=NULL;
    do{
        while(head){
            s[i++]=head;
            head=head->left;
        }
        while(head==NULL && i!=0){  //dealing with right sub-tree
            head=s[i-1];
            if(head->right==NULL || head->right==p){
                printf("%d\n",head->data);
                i--;
                p=head;
                head=NULL;
            }
            else{
                head=head->right;
            }
       }
    }while(i!=0)
}
void LevelTraversal(struct node *head){
   int s=0,e=0;
   struct node * q(1000);
   if(!head) return;
   q[(e++)%1000]=head;
   do{
        head=q[s++];
        print("%d\n",head->data);
        if(head->left!=NULL) q[(e++)%1000]=head->left;
        if(head->right!=NULL) q[(e++)%1000]=head->right;

    }while(abs(s-e)!=0);
}
int main(){

    return 0;
}
