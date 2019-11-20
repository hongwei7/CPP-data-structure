#include <iostream>
#define maxsize 20
#define max_size 50
typedef int elem;
using namespace std;
/*后来定义的一些函数需要stack*/
#include "Stack.h"
#include "queue.h"
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
bool enQueue(queue *&q,elem e)
{
    if(q->front==((q->rear+1)%maxsize))return false;
    q->rear=(q->rear+1)%maxsize;
    q->data[q->rear]=e;
    return true;
}
bool deQueue(queue *&q,elem &e)
{
    if(q->front==q->rear)return false;
    q->front=(q->front+1)%maxsize;
    e=q->data[q->front];
    q->data[q->front]=0;
    return true;
}
void _display(queue *q)
{
    for(int i=0;i<maxsize;i++)
    {
        cout<<q->data[i]<<" ";
    }cout<<endl;
}
void display(queue *q)
{
    if(q->front==q->rear)return;
    for(int i=q->front+1;i!=(q->rear+1)%maxsize;i=(i+1)%maxsize)
    {
        cout<<q->data[i]<<' ';
    }cout<<endl;
}
void reverse_queue(queue *&q)
{
    stack *p=new stack;
    Init_stack(p);
    elem t;
    while(deQueue(q,t))push(p,t);
    Init_queue(q);
    while(!Stack_empty(p))
    {
        pop(p,t);
        enQueue(q,t);
    }
}
int main()
{
    queue *q=new queue;
    elem e;
    Init_queue(q);
    for(int i=1;i<=20;i++)
    {
        if(enQueue(q,i))cout<<"in: "<<i<<endl;
    }
    for(int i=1;i<=12;i++)
    {
        if(deQueue(q,i))cout<<"out: "<<i<<endl;
    }
    for(int i=1;i<=6;i++)
    {
        if(enQueue(q,i))cout<<"in: "<<i<<endl;
    }
    display(q);
    cout<<"point:"<<q->front<<' '<<q->rear<<endl;
    reverse_queue(q);

    display(q);
    cout<<"point:"<<q->front<<' '<<q->rear<<endl;
    reverse_queue(q);
    display(q);
    cout<<"point:"<<q->front<<' '<<q->rear<<endl;
    return 0;
}


