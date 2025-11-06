 #include<stdio.h>
 #include<stdlib.h>
 struct node{
 int data;
 struct node *link;

};
struct node * top=NULL;
void push()
{
struct node * newnode;
newnode=(struct node *)malloc(sizeof(struct node));
if(newnode==NULL){
printf("\n no space \n");
return;
}
newnode->link=NULL;
printf("\nenter the element to insert\n");
scanf("%d",&newnode->data);
if(top==NULL){
top=newnode;
}
else{
newnode->link=top;
top=newnode;
}
printf("\n %d inserted successfully",newnode->data);
}
void pop()
{
struct node *temp=top;
if(top==NULL){
printf("\n stack underflow");
return;
}
printf("\n %d is popped ",temp->data);
top=temp->link;
free(temp);
}
void display()
{
struct node * temp=top;
if(top==NULL){
printf("\n no elements");
return;
}
printf("\n elements in stack are:\n");
while(temp!=NULL){
printf("%d",temp->data);
if(temp->link!=NULL){
printf(",");
}
temp=temp->link;
}
}
void peek()
{
struct node*temp=top;
if(top==NULL){
printf("\n stack underflow");
return;
}
printf("top element is %d",temp->data);
}
void search()
{
struct node*temp=top;
int key,found=0;
if(top==NULL){
printf("\n stack underflow\n");
return;
}
printf("\n enter the element to search\n");
scanf("%d",&key);
while(temp!=NULL){
if(temp->data==key){
printf("\n %d element founded \n",temp->data);
found=1;
}
temp=temp->link;
}
if(!found){
printf("\n element not found");
}
}
void main()
{
int ch;
do{
printf("\n *** Stack ***\n");
printf("\n1:push() \n2:pop() \n3:peek() \n4:display() \n5:search() \n6:exit");
printf("\nenter the choice:");
scanf("%d",&ch);
switch(ch){
case 1:push();
break;
case 2:pop();
break;
case 3:peek();
break;
case 4:display();
break;
case 5:search();
break;
case 6:printf("\n EXIT \n");
break;
}
}
while(ch!=6);
}
