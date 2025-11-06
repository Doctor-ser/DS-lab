#include<stdio.h>
void main()
{
int a[50],i,n,k,flag=0;
printf("enter the limit :");
scanf("%d",&n);
printf("enter the elements :");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
printf("enter the key to be searched :");
scanf("%d",&k);
for(i=0;i<n;i++)
{
 if(a[i]==k)
 {
  flag=1;
  break;
 }
}
if(flag==1)
{
 printf("search successfull,element found at index =%d",a[i]);
}
else
{
 printf("search unsuccessful,element not found");
}
}
