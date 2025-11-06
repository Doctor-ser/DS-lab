#include<stdio.h>
void main()
{
int a[50],b[50],c[100],m,n,i,j,k;
printf("\n enter the size of 1st array :");
scanf("%d",&m);
printf("\n enter the elmnts of 1st array(sorted) :");
for(i=0;i<m;i++)
{
 scanf("%d",&a[i]);
}
printf("\n enter the size of 2nd array :");
scanf("%d",&n);
printf("\n enter the elmnts of 2nd array(sorted) :");
for(i=0;i<n;i++)
{
 scanf("%d",&b[i]);
}
i=0;
j=0;
k=0;
while(i<m&&j<n)
{
 if(a[i]<b[j])
 {
  c[k]=a[i];
  k++;
  i++;
 }
 else
 {
  c[k]=b[j];
  k++;
  j++;
 }
}
while(i<m)
{
 c[k]=a[i];
 i++;
 k++;
}
while(j<n)
{
 c[k]=b[j];
 k++;
 j++;
}
printf("\n merged array =");
for(i=0;i<m+n;i++)
{
 printf("%d \t",c[i]);
}
printf("\n");
}
