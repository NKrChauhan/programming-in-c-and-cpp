#include <stdio.h>
#include <stdlib.h>

int main()
{ char a[]="united kingdom";
   printf("------------------\n");
   printf("%-15.0s\n",a);
   printf("%-15.1s\n",a);
   printf("%-15.2s\n",a);
   printf("%-15.3s\n",a);
   printf("------------------\n");
   int *p;
   p=(int *)calloc(3,sizeof(int));
   p[0]=1;
   p[1]=2;
   printf("%d %d %d ",p[0],p[1],p[2]);
   return 0;
}
 void mode()
 {   int p=1;
     printf("%d",p);
}
