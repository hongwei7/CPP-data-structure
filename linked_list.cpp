#include<iostream>
using namespace std;
typedef int elem;
struct Node
{
	elem data;
	Node * next;
};
Node* create_list(int a[],int n)
{
	Node *link_list=new Node;
	Node *p=link_list;
	for(int i=0;i<n;i++)
	{
		p->data=a[i];
		p->next=new Node;
		p=p->next;

	}
	p->next=NULL;
	return link_list;
}
void Disp_list(Node* L)
{
	Node *p=L;
	while(p->next!=NULL)
	{
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
}
void Init_list(Node *& L)
{
	L=new Node;
	L->next=NULL;
}
void Destroy_list(Node*& L)
{
	Node* p=L;
	while(p!=NULL)
	{
		free(p);
		p=p->next;
	}
	free(p);
	
}
bool Insert_list(Node *& L,int i,elem e)
{
	if(i<=0)return false;
	Node *p=L;
	for(int j=0;j<i-1;j++)
	{
		if(p->next==NULL)return false;
		p=p->next;
	}
	elem temp=p->data;
	Node *q=p->next;
	p->data=e;
	p->next=new Node;
	p=p->next;
	p->data=temp;
	p->next=q;
	return true;
}
bool List_empty(Node *L)
{
	if(L->next==NULL)return true;
	else return false;
}
int List_length(Node *L)
{
	Node *p=L;
	int length=0;
	while(p->next!=NULL)
	{
		length++;
		p=p->next;
	}
	return length;
}
bool Get_elem(Node *L,int i,elem &e)
{
	Node *p=L;
	int j=1;
	while(p->next!=NULL)
	{
		if(i==j)
		{
			e=p->data;
			return true;
		}
		p=p->next;
		j++;
	}
	return false;
}
int Locate_elem(Node *L,elem e)
{
	Node *p=L;
	int j=0;
	while(p->next!=NULL)
	{
		if(p->data==e)return j;
		p=p->next;
		j++;
	}
	return 0;
}
bool Delete_elem(Node *L,int i,elem &e)
{
	if(i<=0)return false;
	Node* p=L,*q;
	int j=0;
	while(p->next!=NULL&&j<=i-1)
	{
		if(i-1==j)
		{
			e=p->data;
			q->next=p->next;
			free(p);
			return true;
		}
		q=p;
		p=p->next;
		j++;
	}
	return false;
}
void delmaxelem(Node * & L)
{
	if(List_empty(L))return;
	Node *p=L,*q=L;
	if(p->next==NULL)
	{
		Init_list(L);
		return;
	}
	elem max=p->data;
	while(p->next!=NULL)
	{
		if((p->next->data)>max)
		{
			max=p->next->data;
			q=p;
		}
		p=p->next;
	}
	p=q->next;
	q->next=p->next;
	free(p);
	return;
}
int main()
{
	int a[8]={1,2,3,4,5,6,7,8};
	elem e;
	Node* list_1=create_list(a,sizeof(a)/sizeof(int));
	Node* list_2;
	Init_list(list_2);
	cout<<"List_length(): "<<List_length(list_2)<<endl;
	Insert_list(list_1,2,10);
	Insert_list(list_2,1,10);
	Insert_list(list_2,1,100);
	Insert_list(list_2,1,1000);
	cout<<"List_length(): "<<List_length(list_2)<<endl;
	cout<<"List_length(): "<<List_length(list_1)<<endl;
	Disp_list(list_1);
	Delete_elem(list_1,8,e);
	Disp_list(list_1);
	delmaxelem(list_1);
	Disp_list(list_1);
	Disp_list(list_2);
	Get_elem(list_1,4,e);
	cout<<"Get_elem(4): "<<e<<endl;
	cout<<"Locate_elem(4): "<<Locate_elem(list_1,4)<<endl;
	Destroy_list(list_1);
	Destroy_list(list_2);
}