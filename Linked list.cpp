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
bool deltfirst(node<int>*&head);
bool deltlast(node<int>*&head);
bool deltitem(node<int>*&head,int item);
bool deltitem2(node<int>*&head,int item);
void delteven(node<int>*&head);
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
	addanyware(head,40);
	print(head);
	print(p);
	cout<<search(head,5)<<endl;
	concat(head,p);
	print(head);
	modify(head,5,69);*/
	print(head);
	deltfirst(head);
	print(head);
	deltlast(head);
	print(head);
	deltitem(head,25);
	print(head);
	deltitem2(head,10);
	print(head);
	fill(head,9);
	addfirst(head,2);
	print(head);
	cout<<"before delete even\n";
	delteven(head);
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
bool deltfirst(node<int>*&head)
{
	if(head==0)
	return 0;
	node<int>*temp=head;
	head=head->next;
	delete temp;
	return 1;
}
bool deltlast(node<int>*&head)
{
	if(head==0)
	return 0;
	node<int>*prev,*follow;
	prev=follow=head;
	while(follow->next!=0)
	{
		prev=follow;
		follow=follow->next;
	}
	if(prev==follow)
	head=0;
	else
	prev->next=follow->next;
	delete follow;
	return 1;
}
bool deltitem(node<int>*&head,int item)
{
	if(head==0)
	return 0;
	node<int>*prev,*follow;
	prev=follow=head;
	while(follow->next!=0)
	{
		if(follow->data==item)
		{
			if(follow==prev)
			head=head->next;
			prev->next=follow->next;
			delete follow;
			return 1;
		}
		prev=follow;
		follow=follow->next;
	}
	if(follow->data==item)
	{
		prev->next=0;
		delete follow;
		return 1;
	}
	return 0;
}
bool deltitem2(node<int>*&head,int item) // another solution 
{
	node<int>*prev,*follow;
	prev=follow=head;
	while(follow!=0 && follow->data !=item)
	{
		prev=follow;
		follow=follow->next;
	}
	if(follow==0)// item not found //
	return 0;
	if(follow==prev)// If the item's location is at the first of the linked list
	head=head->next;
	else
	prev->next=follow->next; 
	
	delete follow;
	return 1;
}
void delteven(node<int>*&head)// same on odd //
{
	node<int>*prev,*follow;
	prev=follow=head;
	while(follow!=0)
	{

		if(follow->data %2==0) 
		{
			if(prev==follow)
			head=head->next;
			else
			prev->next=follow->next;
			delete follow;
			follow=prev;
			
		}
		prev=follow;
		follow=follow->next;
	}
}
