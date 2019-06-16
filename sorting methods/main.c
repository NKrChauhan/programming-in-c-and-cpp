#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *a);
void merge(int *left,int *right,int *a);
void merge_sort(int *a);
void swap(int *num1,int *num2);
int length(int *a);
int Partition(int *a,int start,int end);
int Random_Partition(int *a,int start,int end);
void quick_sort(int *a,int start,int end);

////////////////////////////////////////////////////////////
int main(){
    int a[]={9,8,7,3,4},i;
// insertion_sort(a);
 merge_sort(a);
    for(i=0;i<5;i++)
    printf("%d\n",a[i]);
    return 0;
}
////////////////////////////////////////////////////////////
void swap(int *num1,int *num2){
    int temp=*num2;
    *num2=*num1;
    *num1=temp;
}
////////////////////////////////////////////////////////////
void insertion_sort(int *a){
 int n=length(a);
 int i,j;
 for(i=1;i<n;i++){
    int temp=a[i];
    for(j=0;j<i;j++)
        if(temp<a[j]){
            swap(&temp,&a[j]);
        }
         a[i]=temp;
}}
/////////////////////////////////////////////////////////////     part of merge sort
void merge(int* left,int *right,int *a){
    int i=0,j=0,k=0;
    int  l=length(left),m=length(right);
    while(i<l && j<m){
        if(left[i]<right[j])
            a[k++]=left[i++];
        else
            a[k++]=right[j++];
    }
  while(i<l)
    a[k++]=left[i++];
  while(j<m)
    a[k++]=right[j++];

}
///////////////////
void merge_sort(int *a){
    int n=length(a);
    int i,mid =n/2;
    if(n<2)
        return;
    else{
    int *left=malloc(sizeof(int)*mid);
    int *right=malloc(sizeof(int)*(n-mid));
    for(i=0;i<mid;i++)
        left[i]=a[i];
    for(i=0;i<(n-mid);i++)
        right[i]=a[n-mid+i];
    merge_sort(left);
    merge_sort(right);
    merge(left,right,a);
}}
//////////////////////////////////////////////////////////////
int length(int  *a){
int i=0;
while(a[i]!='\0')                                                                                        //difference of 18 why?????????/
    i++;
return (i-18);
}
//////////////////////////////////////////////////////////////
void quick_sort(int *a,int start,int end){
if(start<end){
// int pindex=Random_partition(a,start,end);
int pindex=Partition(a,start,end);
quick_sort(a,start,pindex-1);
quick_sort(a,pindex+1,end);
}}
////////////////////////////////    part of quick sort pivot is taken coz i have to copy paste the whole thing in Random_partition
int Partition(int *a,int start,int end){
int pivot=a[end],index=0,i;
for(i=0;i<end;i++)
if(a[i]>pivot){
    swap(&a[i],&a[index++]);
}
swap(&a[index],a[end]);
return index;
}
///////////////////////////////
int Random_Partition(int *a,int start, int end){
int pivot=rand()%end;
int index=0,i;
for(i=0;i<end-1;i++)
if(a[i]>pivot){
    swap(&a[i],&a[index++]);
}
swap(&a[index],a[end]);
return index;
}
//<-----------------------------------------------------------<<<//
