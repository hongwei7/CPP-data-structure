#include<iostream>
using namespace std;
#include "ListNode.h"
void Init_list(sqlist * & L)
{
    L=(sqlist *)malloc(sizeof(sqlist));
    L->length=0;
}
void Destroy_list(sqlist *& L)
{
	free(L);
}
void Disp_list(sqlist * L)
{
	for(int i=0;i<L->length;i++)
	{
		cout<<L->data[i]<<' ';
	}
	cout<<endl;
}
void Create_list(sqlist * & L,int *a,int n)
{	
	for(int i=0;i<n;i++)
	{
		L->data[i]=a[i];
		L->length=L->length+1;
	}
}
bool List_empty(sqlist * L)
{
	return (L->length==0);
}
int List_length(sqlist * L)
{
	return L->length;
}
bool Get_item(sqlist *L,int i,elem &e)
{
	if(i<=L->length&&i>0)
	{
		e=L->data[i-1];
		return true;
	}
	else return false;
}
int Locate_item(sqlist *L , elem e)
{
	for(int i=0;i<L->length;i++)
	{
		if(e==L->data[i])return i+1;
	}
	return 0;
}
bool List_insert(sqlist * & L,elem e,int i)
{
	if(i>L->length||i<1)return false;
	else
	{
        for(int j=L->length;j>=i;j--)
        {
            L->data[j]=L->data[j-1];
        }
        L->data[i-1]=e;
        L->length++;
        return true;
	}
}
bool List_delete(sqlist * & L,int i,elem &e)
{
    if(i>L->length||i<1)return false;
    else
    {
        e=L->data[i-1];
        for(int j=i-1;j<L->length-1;j++)
        {
            L->data[j]=L->data[j+1];
        }
        L->length--;
        return true;
    }
}
void Del_node(sqlist * & L,elem e)//删除所有值为e的node
{
    int k=0;
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]!=e)
            {
                L->data[k]=L->data[i];
                k++;
            }
    }
    L->length=k;
}
void Del_nodes(sqlist * & L,elem x,elem y)
{
    int k=0;
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]>y||L->data[i]<x)
            {
                L->data[k]=L->data[i];
                k++;
            }
    }
    L->length=k;
}
void partition(sqlist * & L)
{
    elem p=L->data[0];
    int i=0,j=L->length-1;
    while(i<j)
    {
        for(;j>i;j--)
        {
            if(L->data[j]<p)break;
        }
        L->data[i]=L->data[j];
        for(;i<j;i++)
        {
            if(L->data[i]>p)break;
        }
        L->data[j]=L->data[i];
    }
    L->data[i]=p;
}
void partition_byZero(sqlist * & L)
{
    elem p=L->data[0];
    int i=0,j=L->length-1;
    while(i<j)
    {
        for(;j>i;j--)
        {
            if(L->data[j]<0)break;
        }
        L->data[i]=L->data[j];
        for(;i<j;i++)
        {
            if(L->data[i]>0)break;
        }
        L->data[j]=L->data[i];
    }
    L->data[i]=p;
}
void partition1(sqlist * & L)
{
    elem p=L->data[0],q=p%2;
    int i=0,j=L->length-1;
    while(i<j)
    {
        for(;j>i;j--)
        {
            if(L->data[j]%2==q)break;
        }
        L->data[i]=L->data[j];
        for(;i<j;i++)
        {
            if(L->data[i]%2!=q)break;
        }
        L->data[j]=L->data[i];
    }
    L->data[i]=p;
}
int quick_partition(sqlist * & L,int i0,int n)
{
    elem p=L->data[i0];
    int i=i0,j=n-1;
    while(i<j)
    {
        for(;j>i;j--)
        {
            if(L->data[j]<p)break;
        }
        L->data[i]=L->data[j];
        for(;i<j;i++)
        {
            if(L->data[i]>p)break;
        }
        L->data[j]=L->data[i];
    }
    L->data[i]=p;
    return i;
}
void Quick_sort(sqlist *&L,int i=-1,int j=-1)
{
    if(i==-1&&j==-1)
        {
            Quick_sort(L,0,L->length);
            return;
        }
    if(j-i>1)
        {
            int divide_point=quick_partition(L,i,j);
            Quick_sort(L,i,divide_point);
            Quick_sort(L,divide_point+1,j);
        }

}

int main()
{
    int a[7]={-7,5,-2,4,-1,-8,9};
    sqlist * L;
    Init_list(L);
    Create_list(L,a,7);
    Disp_list(L);
    elem b=0;
    Get_item(L,2,b);
    cout<<b<<endl;
    List_insert(L,12,2);
    Disp_list(L);
    List_insert(L,5,3);
    Disp_list(L);
    List_insert(L,6,4);
    Disp_list(L);
    List_delete(L,3,b);
    Disp_list(L);
    cout<<b<<endl;
    List_insert(L,5,3);
    List_insert(L,5,5);
    List_insert(L,5,7);
    Disp_list(L);
    Del_node(L,5);
    List_insert(L,3,3);
    List_insert(L,11,5);
    List_insert(L,10,7);
    List_insert(L,5,1);
    Del_nodes(L,3,6);
    Disp_list(L);
    partition(L);
    Disp_list(L);
    partition1(L);
    Disp_list(L);
    partition_byZero(L);
    Disp_list(L);
    cout<<"sorted:"<<endl;
    Quick_sort(L);
    Disp_list(L);
}
