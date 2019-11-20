/*一般二叉树 链式存储*/
#include<stdio.h>
#include<iostream>
#include<limits>
#define elem char
#define maxsize 50
struct Node
{
    elem data;
    Node * lchild,*rchild;
};
void CreateBTree(Node *& b,char *str)
{
    Node * St[maxsize],*p;
    int top=-1,k,j=0;
    char ch;
    b=NULL;
    ch=str[j];
    while(ch!='\0')
    {
        switch(ch)
        {
            case '(':top++;St[top]=p;k=1;break;
            case ')':top--;break;
            case ',':k=2;break;
            default:p=new Node;
            p->data=ch;
            p->lchild=p->rchild=NULL;
            if(b==NULL)
                b=p;
            else switch(k)
            {
                case 1:St[top]->lchild=p;break;
                case 2:St[top]->rchild=p;break;
            }
        }
        j++;
        ch=str[j];
    }
}
void DestroyBtree(Node *& b)
{
    if(b!=NULL)
    {
        DestroyBtree(b->lchild);
        DestroyBtree(b->rchild);
        delete(b);
    }
}
Node *FindNode(Node *b,elem s)
{
    Node *p;
    if(b==NULL)
        return NULL;
    else if(b->data==s)
        return b;
    else 
    {
        p=FindNode(b->lchild,s);
        if(p!=NULL)
            return p;
        else 
            return FindNode(b->rchild,s);
    }
}
elem FindMinNode(Node *b,elem value=(std::numeric_limits<char>::max)())
{
    if(b==NULL)
        return value;
    if((value)>(b->data)){
        value=b->data;
    }
    return std::min(FindMinNode(b->lchild,value),FindMinNode(b->rchild,value));
}
int CountSingleChildNode(Node *b)
{
    if(b==NULL||(b->lchild==NULL&&b->rchild==NULL))
        return 0;
    if(b->lchild!=NULL&&b->rchild!=NULL)
        return CountSingleChildNode(b->lchild)+CountSingleChildNode(b->rchild);
    else
        return 1+CountSingleChildNode(b->lchild)+CountSingleChildNode(b->rchild);
}
int BTheight(Node *b)
{
    int leftdepth,rightdepth;
    if(b==NULL)return 0;
    else{
        leftdepth=BTheight(b->lchild);
        rightdepth=BTheight(b->rchild);
    }
    return (leftdepth>rightdepth)?(leftdepth+1):(rightdepth+1);
}
void DispBTree(Node *b)
{
    if(b!=NULL){
        printf("%c",b->data);
        if(!(b->lchild==NULL&&b->rchild==NULL)){
            printf("%c",'(' );
            DispBTree(b->lchild);
            printf("%c",',');
            DispBTree(b->rchild);
            printf("%c",')');
        }
    }
}
Node * create_tree_by_list(elem *pre,elem *in,int n)
{
    Node *b;
    elem *p;
    int k;
    if(n<=0)return NULL;
    b=new Node;
    b->data=*pre;
    //printf("%s\t%s\n",pre ,in );
    for(p=in;p<in+n;p++){
        if(*p==*pre)
            break;
    }
    k=p-in;
    b->lchild=create_tree_by_list(pre+1,in,k);
    b->rchild=create_tree_by_list(pre+1+k,p+1,n-k-1);
    return b;
}

//层次访问 使用队列
//******************STACK***********************
struct queue
{
    Node * data[maxsize];
    int front,rear;
};
void Init_queue(queue* &q)
{
    q=new queue;
    q->front=0;
    q->rear=0;
}
void Destroy_queue(queue *&q)
{
    free(q);
}
bool queue_empty(queue *q)
{
    return q->front==q->rear;
}
bool enQueue(queue *&q,Node * e)
{
    if(q->front==((q->rear+1)%maxsize))return false;
    q->rear=(q->rear+1)%maxsize;
    q->data[q->rear]=e;
    return true;
}
bool deQueue(queue *&q,Node * &e)
{
    if(q->front==q->rear)return false;
    q->front=(q->front+1)%maxsize;
    e=q->data[q->front];
    q->data[q->front]=0;
    return true;
}
//*******************STACK***********************


void ascess_by_level(Node *tree)
{
    Node *p=tree;
    queue * q= new queue;
    Init_queue(q);
    enQueue(q,p);
    while(queue_empty(q)==false){
        deQueue(q,p);
        printf("%c",p->data);
        if(p->lchild!=NULL)
            enQueue(q,p->lchild);
        if(p->rchild!=NULL)
            enQueue(q,p->rchild);
    }
    printf("\n");
}

//halfman tree
struct HTNode
{
    char data;
    int lnode,rnode,parent;
    double weight;
};
void create_HT(HTNode ht[],int n0)
{
    int i,k,lnode,rnode;
    double min1,min2;
    for(i=0;i<2*(n0-1);i++){
        ht[i].parent=ht[i].lnode=ht[i].rnode=-1;
    }
    for(i=n0;i<=2*n0-2;i++){
        min1=min2=32767;
        lnode=rnode=-1;
        for(k=0;k<i-1;k++)
            if(ht[k].parent==-1){
                if(ht[k].weight<min1){
                    min2=min1;rnode=lnode;
                    min1=ht[k].weight;lnode=k;
                }
                else if(ht[k].weight<min2){
                    min2=ht[k].weight;rnode=k;
                }
            }
        ht[i].weight=ht[lnode].weight+ht[rnode].weight;
        ht[i].lnode=lnode;
        ht[i].rnode=rnode;
        ht[lnode].parent=i;ht[rnode].parent=i;
        ht[i].data='N';
    }
}
void build_halfman_byweight(HTNode ht[],double weight[],int n0)
{
    for(int i=0;i<n0;i++){
        HTNode temp;
        temp.weight=weight[i];
        temp.data='a'+i;
        ht[i]=temp;
    }
    /*print
    printf("\n****** waiting nodes ******\n");
    printf("data\tweights\n");
    for (int i = 0; i < n0; ++i)
    {
        printf("%c\t%f\n",ht[i].data,ht[i].weight);
    }
    */
    create_HT(ht,n0);
    /*
    printf("\n");
    printf("\n****** halfman tree ******\n");
    printf("data\tweights\t\tlnode\trnode\tparent\n");
    for(int i=0;i<2*n0-1;i++){
        printf("%c\t%f\t%d\t%d\t%d\n",ht[i].data,ht[i].weight,ht[i].lnode,ht[i].rnode,ht[i].parent);
    }
    */
}

int main()
{
    char str[]="a(b,f(k(c,d),e)";
    Node *tree=new Node;
    CreateBTree(tree,str);
    putchar(tree->rchild->lchild->lchild->data);
    //printf(" %8d\n",FindNode(tree,'d'));
    printf("DEPTH: %d\n",BTheight(tree));
    DispBTree(tree);
    printf("\n");
    //DestroyBtree(tree);
    elem pre[]="abdgcef",in[]="dgbaecf";
    Node *tree1=create_tree_by_list(pre,in,7);
    ascess_by_level(tree1);
    DispBTree(tree1);
    printf("\n");
    char str2[]="a(b(k,c(,d)),)";
    Node *tree2=new Node;
    CreateBTree(tree2,str2);
    printf("test\n");
    DispBTree(tree2);
    printf("\nCountSingleChildNode : %d\n",CountSingleChildNode(tree2));
    printf("tree's minvalue:%c\n",FindMinNode(tree2) ); 
    int n0=6;
    HTNode ht[20];
    double weight[6]={2,3,4,7,8,9};
    build_halfman_byweight(ht,weight,6);
}

