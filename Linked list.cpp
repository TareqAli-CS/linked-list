#include <iostream>
using namespace std;
template <class T>
struct node
{
	T data;
	node<T>*next;
	node()
	{
		next=0;
	}
	node(T item)
	{
		data=item;
		next=0;
	}
};
int number=10;
void print(node<int>*head);
void count(node<int>*head);
bool addfirst(node<int>*&head,int item);
void fill(node<int>*&head,int number);
bool addlast(node<int>*&head,int item);
bool addanyware(node<int>*&head,int item);
bool search(node<int>*head,int item);
void concat(node <int>*&head,node<int>*p);
void modify(node<int>*&head,int x,int y);
main()
{
	node<int>*head=new node<int>(5);
	node<int>*p=new node<int>(10);
	/*head->next=new node<int>(10);
	head->next->next=new node<int>(15);
	head->next->next->next=new node<int>(20);
	head->next->next->next->next=new node<int>(25);*/
	fill(head,5);
	fill(p,5);
/*	print(head);
	count(head);
	addfirst(head,3);
	print(head);
	addlast(head,35);
	print(head);
	addanyware(head,40);*/
	print(head);
	print(p);
	cout<<search(head,5)<<endl;
	concat(head,p);
	print(head);
	modify(head,5,69);
	print(head);
	cout<<"test"<<endl;
}
void fill(node<int>*&head,int n)
{
	node<int>*temp=head;
	
	for(int i=0;i<n;i++,number+=5)
	{
		temp->next=new node<int>;
		temp=temp->next;
		temp->data=number;
	}
}
void print(node<int>*head)
{
	while(head!=0)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void count(node<int>*head)
{
	int c=0;
	while(head!=0)
	{
		c++;
		head=head->next;
	}
	cout<<"number of item: "<<c<<endl;
}
bool addfirst(node<int>*&head,int item)
{
	node<int>*temp=new node<int>(item);
	if(temp==0)
	return 0;
	temp->next=head;
	head=temp;
	return 1;
}
bool addlast(node<int>*&head,int item)
{
	node<int>*temp=new node<int>(item);
	node<int>*p=head;
	if(temp==0)
	return 0;
	if(temp!=0)
	{
		if(head==0)
		head=temp;
		else
		{
			while(p->next!=0)
			p=p->next;
			p->next=temp;
		}
	}
	return 1;
}
bool addanyware(node<int>*&head,int item)
{
	node<int>*temp=new node<int>(item);
	if(temp==0)
	return 0;
	node<int>*follow=head;
	node<int>*prev=head;
	if(head==0 || head->data>item)
	{
		temp->next=follow;
		head=temp;
	}
	else
	{	
		while(follow!=0 && follow->data<item)
		{
			prev=follow;
			follow=follow->next;
		}
		temp->next=follow;
		prev->next=temp;
	}
	return 1;
}
bool search(node<int>*head,int item)
{
	while(head!=0)
	{
		if(head->data==item)
		return 1;
		head=head->next;
	}
	return 0;
	
}
void concat(node <int>*&head,node<int>*p)
{
	node<int>*temp=p;
	while(p->next!=0)
	p=p->next;
	p->next=head;
	head=temp;
}
void modify(node<int>*&head,int x,int y)
{
	node<int>*p=head;
	while(p!=0)
	{
		if(p->data==x)
		{
			
			p->data=y;
		}
		p=p->next;
	}
	
	
}