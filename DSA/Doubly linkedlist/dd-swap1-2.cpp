#include<iostream>
#include<malloc.h>
using namespace std;
struct Node
{
	int data;
	Node *next , *prev;        //inter-referential pointer
};
Node *temp , *ttemp , *first;
void init()
{
	first=temp=ttemp=NULL;
}
void create_first(int x)
{
	first=(Node *)malloc(sizeof(Node));
	first->data=x;
	first->next=NULL;
	first->prev=NULL;
}
void addnodes(int x)
{
	temp=first;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	ttemp=(Node *)malloc(sizeof(Node));
	ttemp->data=x;
	ttemp->next=NULL;
	ttemp->prev=temp;
	temp->next=ttemp;
}

////swap 1st and 2nd Node
void swap()
{
	temp=first;
	ttemp=temp->next;
	temp->next=ttemp->next;
	temp->prev=ttemp;
	ttemp->next=first;
	ttemp->prev=NULL;
	first=ttemp;
}
void display()
{
	temp=first;
	while(temp!=NULL)
	{
		cout<<"\n"<<temp->data;
		temp=temp->next;
	}
}
int main()
{
	init();
	create_first(10);
	addnodes(20);
	addnodes(30);
	addnodes(40);
	addnodes(50);
	addnodes(60);
	addnodes(70);
	addnodes(80);
	display();
	cout<<"\n after swapping 1st and 2nd node";
	swap();
	display();
}
