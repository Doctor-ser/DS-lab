#include <stdio.h>
void main(){
int a[50],n,i;
printf("Enter the no. of element");
scanf("%d",&n);
printf("Enter the elements");
for(i=0;i<=n;i++){
scanf("%d",&a[i]);
}
printf("The Array Elements are:");
for(i=0;i<=n;i++){
printf("%d",a[i]);
}
}
