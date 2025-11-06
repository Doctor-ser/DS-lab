#include <stdio.h>
void main(){
int a[50],n,i,item,p;
printf("Enter the no. of element");
scanf("%d",&n);
printf("Enter the elements");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("\nThe Array Elements are:");
for(i=0;i<n;i++){
printf("%d",a[i]);
}
printf("Enter the Position want to insert");
scanf("%d",&p);
printf("Enter the elements to be Inserted");
scanf("%d",&item);
n=n+1;
for(i=n;i>=p-1;i--){
a[i+1]=a[i];
a[p-1]=item;
printf("The new Array :");
for(i=0;i<n;i++){
printf("%d",a[i]);
}
}
}
