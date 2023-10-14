#include<iostream>
#include<malloc.h>
using namespace std;
struct Node
{
	int data;
	Node *next , *prev;        //inter-referential pointer
};
Node *temp , *ttemp , *first , *p;
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

////add after a given data
void add_after(int x , int y)
{
	temp=first;
	while(temp->data!=x)	
	{
		temp=temp->next;
	}
	ttemp=temp->next;
	p=(Node *)malloc(sizeof(Node));
	p->data=y;
	p->next=ttemp;
	p->prev=temp;
	temp->next=p;
	ttemp->prev=p;
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
	cout<<"\n after adding a node";
	add_after(40,566);
	display();
}
