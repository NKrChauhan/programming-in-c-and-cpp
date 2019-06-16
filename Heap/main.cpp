#include <iostream>

using namespace std;

struct heap{
    int s;
    int *a;
}

struct *heapcreation(int s){
    struct heap h;
    int *a=(int*)malloc(s*sizeof(int));
    h->s=s;
    h->a=a;
    return h;
}

void percolate_down(struct heap *h,int i){
    int l=2*i+1;
    int r=2*i+2;
    int maxim=s;
    if(l<s && h->a[i]>h->a[l]){
        int temp=h->a[i];
        h->a[i]=h->a[l];
        h->a[l]=temp;
        maxim=l
    }
    if(r<s && h->a[i]>h->a[r]){
        int temp=h->a[i];
        h->a[i]=h->a[r];
        h->ar[r]=temp;
        maxim=r
    }
    if(maxim!=s) percolate_down(h,maxim);
}


void percolate_up(struct heap *h,int i){
    int p=(i-1)/2;
    int maxim=-1;
    if(p>=0 && h->a[i]<h->a[p]){
        int temp=h->a[i];
        h->a[i]=h->a[p];
        h->a[p]=temp;
        maxim=l
    }
    if(maxim!=-1) percolate_up(h,maxim);
}

int searching(struct heap h){

}

struct heap *insertion(struct heap *h,int s,int data){


}

void Deletion(struct heap *h,int *s){


}


int main()
{

    return 0;
}

