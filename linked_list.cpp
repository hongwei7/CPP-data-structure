#include<iostream>
using namespace std;
typedef int elem;
struct Node
{
    elem data;
    Node * next;
};
Node* create_list_head(int a[],int n)
{
    Node *link_list=new Node;
    Node *p=link_list,*q;
    p->next=NULL;
    for(int i=0;i<n;i++)
    {
        q=new Node;
        q->data=a[i];
        q->next=p->next;
        p->next=q;
    }
    return link_list;
}
Node* create_list_tail(int a[],int n)
{
    Node *link_list=new Node;
    Node *p=link_list;
    for(int i=0;i<n;i++)
    {
        p->next=new Node;
        p=p->next;
        p->data=a[i];
    }
    p->next=NULL;
    return link_list;
}
void Disp_list(Node* L)
{
    Node *p=L;
    while(p->next!=NULL)
    {
        p=p->next;
        cout<<p->data<<' ';
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
    if(!(L->next==NULL&&i==1))
    {
        for(int j=0;j<i;j++)
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
    L->next=new Node;
    L->next->data=e;
    L->next->next=NULL;
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
    Node *p=L->next;
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
    Node *p=L->next;
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
    Node* p=L->next,*q;
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
    Node *p=L->next,*q=L;
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
void sort(Node *& L)
{
    Node *origin=L->next->next,*next,*select;
    L->next->next=NULL;
    while(origin!=NULL)
    {
        next=origin->next;
        select=L;
        while(select->next!=NULL&&select->next->data<origin->data)
            select=select->next;
        origin->next=select->next;
        select->next=origin;
        origin=next;
    }
}
bool Insert_node_before_max(Node *& L,elem e)
{
    if(L->next==NULL)return false;
    Node *p=L->next,*max=L;
    while(p->next!=NULL)
    {
        if(p->next->data>max->next->data)
        {
            max=p;
            cout<<max->next->data<<" t"<<endl;
        }
        p=p->next;
    }
    p=max->next;
    max->next=new Node;
    max=max->next;
    max->data=e;
    max->next=p;
    return true;
}
bool reverse(Node *&L)//反转数组
{
    if(L->next==NULL)return false;
    Node *p=L->next,*q=L->next->next;
    L->next=NULL;
    while(q!=NULL)
    {
        p=q->next;
        q->next=L->next;
        L->next=q;
        q=p;
    }
    return true;
}
void split_two(Node *& L,Node *&L1,Node *& L2)//间隔分割
{
    Node *r,*p,*q;
    L1=L;
    p=L1;
    r=L->next;
    L2->next=NULL;
    while(r!=NULL)
    {
        p->next=r;
        p=p->next;

        r=r->next;
        if(r==NULL)break;
        q=r->next;

        r->next=L2->next;
        L2->next=r;

        r=q;
    }
    p->next=NULL;
}
void output_free(Node *& L)
{
    Node *p,*max;
    while(L->next!=NULL)
    {
        max=L;
        p=L;
        while(p->next!=NULL)
        {
            if(p->next->data>max->next->data)
            {
                max=p;
            }
        p=p->next;
        }
    p=max->next;
    max->next=p->next;
    cout<<p->data<<" ";
    free(p);
    }
    cout<<endl;
}
void combine(Node *&hc,Node *L1,Node* L2)
{
    Node *p=L1->next;
    hc=new Node;
    Node *hcp=hc;
    while(p!=NULL)
        {
            hcp->next=new Node;
            hcp=hcp->next;
            hcp->data=p->data;
            p=p->next;
        }
    p=L2->next;
    while(p!=NULL)
        {
            hcp->next=new Node;
            hcp=hcp->next;
            hcp->data=p->data;
            p=p->next;
        }
        hcp->next=hc;
}
int main()
{
    int a[8]={12,24,3,40,53,6,72,8};
    elem e;
    Node* list_1_t=create_list_tail(a,sizeof(a)/sizeof(int));
    Node* list_1=create_list_head(a,sizeof(a)/sizeof(int));
    Disp_list(list_1_t);
    Disp_list(list_1);
    Node* list_2;
    Init_list(list_2);
    cout<<"List_length(): "<<List_length(list_2)<<endl;
    Insert_list(list_1,6,4);
    Insert_list(list_2,1,10);
    Insert_list(list_2,1,100);
    Insert_list(list_2,1,1000);
    Insert_list(list_1,4,1000);
    Insert_list(list_1,5,2000);
    Disp_list(list_2); 
    cout<<"List_length(): "<<List_length(list_2)<<endl;
    cout<<"List_length(): "<<List_length(list_1)<<endl;
    Disp_list(list_1);
    Delete_elem(list_1,2,e);
    Disp_list(list_1);
    delmaxelem(list_1);
    Disp_list(list_1);
    Disp_list(list_2);
    Get_elem(list_1,4,e);
    cout<<"Get_elem(4): "<<e<<endl;
    cout<<"Locate_elem(53): "<<Locate_elem(list_1,53)<<endl;
    Disp_list(list_1);
    Insert_node_before_max(list_1,45);
    Disp_list(list_1);
    sort(list_1);
    Disp_list(list_1);
    reverse(list_1);
    Disp_list(list_1);
    Node *L1=new Node;
    Node *L2=new Node;
    split_two(list_1,L1,L2);
    cout<<"L1:"<<endl;
    Disp_list(L1);
    cout<<"L2:"<<endl;
    Disp_list(L2);
    Node* hc;
    combine(hc,list_1,list_2);
    cout<<"hc:"<<endl;
    Disp_list(hc);
    cout<<"free L1:"<<endl;
    output_free(L1);
    Destroy_list(list_1);
    Destroy_list(list_2);
}