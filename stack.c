#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int item)
{
 if(top == MAX -1)
 {
  printf("\n stack overflow ");
  return;
 }
 stack[++top]=item;
 printf("\n %d pushed to stack",item);
}
void pop()
{
if(top==-1)
{
 printf("\n stack underflow ");
 return;
}
printf("\n%d popped from stack",stack[top--]);
}
void peek()
{
 if(top== -1)
 {
 printf("\n stack is empty");
 return;
}
printf("\n top element is %d",stack[top]);
}
void display()
{
if(top==-1)
{
printf("\n stack is empty");
return;
}
printf("\n stack elements are:");
for(int i=top;i>=0;i--)
{
printf("%d \t",stack[i]);
}
}

int main()
{
int ch,val;
while(1){
printf("\n\n stack operations menu:");
printf("\n1.push");
printf("\n2.pop");
printf("\n3.peek");
printf("\n4.display");
printf("\n5.exit");
printf("\nenter your choice :");
scanf("%d",&ch);
switch(ch){
  case 1:printf("\n enter value to push:");
         scanf("%d",&val);
         push(val);
         break;
  case 2:pop();
         break;
  case 3:peek();
         break;
  case 4:display();
         break;
  case 5:printf("\n exiting pgm");
         return 0;
         
  default:printf("\n invalid choice");
  }
  }
  return 0;
 }
 
