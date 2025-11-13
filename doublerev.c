#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
	int data;
	struct node*Llink;
	struct node*Rlink;
};
struct node*head=NULL;

void insertFirst()
{
	struct node*newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n No Space Available");
		return;
	}
	newnode->Llink=NULL;
	newnode->Rlink=NULL;
	printf("\n Enter the Element to insert: ");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->Rlink=head;
		head->Llink=newnode;
		head=newnode;
	}
	printf("\n %d inserted successfully",newnode->data);
}

void insertLast()
{
	struct node*newnode,*temp=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n Error:No Space Available for a new node.\n");
		return;
	}
	newnode->Llink=NULL;
	newnode->Rlink=NULL;
	printf("\n Enter the element to insert: ");
	scanf("%d",&newnode->data);
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		while(temp->Rlink!=NULL)
		{
			temp=temp->Rlink;
		}
		newnode->Llink=temp;
		temp->Rlink=newnode;
	}
	printf("\n %d inserted successfully",newnode->data);
}

void display()
{
	struct node*temp=head;
	if(head==NULL)
	{
		printf("\n NO ELEMENTS IN LIST \t");
		return;
	}
	else
	{
		printf("\n **ELEMENTS IN LIST**\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->Rlink;
		}
	}
}

void displayReverse()
{
	struct node *temp=head;
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY \n");
		return;
	}

	while(temp->Rlink!=NULL)
	{
		temp=temp->Rlink; 
	}

	printf("\n **ELEMENTS IN REVERSE ORDER**\n");
	while(temp!=NULL)
	{
		printf("%d\t",temp->data);
		temp=temp->Llink;
	}
}

void insertLocation()
{
	struct node*newnode,*temp=head,*nxt;
	int key;
	newnode=(struct node *)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\n Error:No Space avaiable for a new node.\n");
		return;
	}
	if(head==NULL)
	{
		printf("\n List is Empty\n");
	}
	else
	{
		printf("\n Enter the Key where after you want to insert the element: ");
		scanf("%d",&key);
		while(temp!=NULL && temp->data!=key)
		{
			temp=temp->Rlink;
		}
		if(temp==NULL)
		{
			printf("\n NO ELEMENT FOUND \n");
			return;
		}
		printf("\n Enter the element to insert: ");
		scanf("%d",&newnode->data);
		if(temp->Rlink==NULL)
		{
			newnode->Llink=temp;
			newnode->Rlink=NULL;
			temp->Rlink=newnode;
		}
		else
		{
			nxt=temp->Rlink;
			newnode->Llink=temp;
			newnode->Rlink=nxt;
			temp->Rlink=newnode;
			nxt->Llink=newnode;
		}
		printf("\n %d inserted successfully",newnode->data);
	}
}

void deleteFirst()
{
	struct node*temp=head,*nxt;
	if(head==NULL)
	{
		printf("\n LIST EMPTY \n");
		return;
	}
	printf("\n %d is deleted",temp->data);
	if(temp->Rlink==NULL)
	{
		head=NULL;
	}
	else
	{
		nxt=temp->Rlink; 
		head=nxt;
		nxt->Llink=NULL;
	} 
	free(temp);
}

void deleteLast()
{
	struct node*temp=head,*nxt;
	if(head==NULL)
	{
		printf("\n List is empty \n");
		return;
	}
	if(temp->Rlink==NULL)
	{
		printf("\n %d is deleted",temp->data);
		head=NULL;
	}
	else
	{
		while(temp->Rlink!=NULL)
		{
			temp=temp->Rlink;
		}
		printf("\n %d is deleted",temp->data);
		nxt=temp->Llink;
		nxt->Rlink=NULL;
	}
	free(temp);
}

void deleteLocation()
{
	struct node*temp=head,*prev,*next;
	int key;
	if(head==NULL)
	{
		printf("\n LIST IS EMPTY \n");
		return;
	}
	printf("\n Enter the key which you want to delete: ");
	scanf("%d",&key);
	while(temp!=NULL && temp->data!=key)
	{
		temp=temp->Rlink;
	}
	if(temp==NULL)
	{
		printf("\n NO ELEMENT FOUND \n");
		return;
	}
	if(temp->Llink==NULL)
	{
		head=temp->Rlink;
		if(head!=NULL)
		{
			head->Llink=NULL;
		}
	}
	else if(temp->Rlink==NULL)
	{
		temp->Llink->Rlink=NULL;
	}
	else
	{
		prev=temp->Llink;
		next=temp->Rlink;
		prev->Rlink=next;
		next->Llink=prev;
	}
	printf("\n %d Deleted Successfully \n",temp->data);
	free(temp);
}

void search()
{
	int key,pos=1,found=0;
	struct node * temp=head;
	if(head==NULL)
	{
		printf("\n LIST EMPTY \n");
		return;
	}
	printf("\n Enter the key to search: ");
	scanf("%d",&key);
	while(temp!=NULL)
	{
		if(temp->data==key)
		{
			printf("\n %d is found at location %d",temp->data,pos);
			found=1;
		}
		temp=temp->Rlink;
		pos++;
	}

	if(!found)
	{
		printf("\n ELEMENT NOT FOUND \n");
	}
}

void main()
{
	int choice;
	do
	{
		printf("\n *****DOUBLY LINKED LIST******\n");
		printf("\n 1->insertFirst \n 2->insertLast \n 3->insertLocation \n 4->deleteFirst \n 5->deleteLast \n 6->deleteLocation \n 7->Search \n 8->Display \n 9->Exit \n 10->DisplayReverse \n");
		printf("Enter the choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insertFirst();
				break;
			case 2:insertLast();
				break;
			case 3:insertLocation();
				break;
			case 4:deleteFirst();
				break;
			case 5:deleteLast();
				break;
			case 6:deleteLocation();
				break;
			case 7:search();
				break;
			case 8:display();
				break;
			case 9:printf("\n EXIT \n");
				exit(0);
			case 10:displayReverse();
				break;
			default:printf("Enter valid choice");
				break;
		}
	} while(choice!=9);
}
