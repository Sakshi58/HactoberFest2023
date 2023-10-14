#include<iostream>
#include<malloc.h>
struct Node
{
	int data;
	Node *next , *prev;
};
Node *first , *temp , *ttemp , *p;

///initialization
void init()
{
	first=temp=ttemp=NULL;
}
///creating the first node
void create_first(int x)
{
	first=(Node *)malloc(sizeof(Node));
	first->data=x;
	first->next=first->prev=NULL;
}

///adding other nodes
void add_nodes(int x)
{
	temp=first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	//creating another memory block
	ttemp=(Node  *)malloc(sizeof(Node));
	ttemp->data=x;
	ttemp->next=NULL;
	ttemp->prev=temp;
	temp->next=ttemp;
}

//displaying
void disp()
{
	temp=first;
	while(temp!=NULL)
	{
		std::cout<<"\n"<<temp->data;
		temp=temp->next;
	}
}

//driver code
int main()
{
	init();
	create_first(10);
	add_nodes(20);
	add_nodes(50);
	add_nodes(70);
	add_nodes(80);
	add_nodes(90);
	add_nodes(60);
	add_nodes(30);
	disp();
}
