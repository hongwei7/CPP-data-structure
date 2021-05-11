#define elem char
#define maxsize 50



//******************BTNODE**********************
struct Node
{
    elem data;
    Node * lchild,*rchild;
};
//******************BTNODE**********************


//******************Halfman**********************
struct HTNode
{
    char data;
    int lnode,rnode,parent;
    double weight;
};
//******************Halfman**********************


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
