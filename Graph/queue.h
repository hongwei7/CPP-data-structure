using namespace std;
#define elem int

#define maxsize 50
struct queue
{
    elem data[maxsize];
    int front,rear;
};
void Init_queue(queue* &q)
{
    q = new queue;
    q->front = 0;
    q->rear = 0;
}
void Destroy_queue(queue *&q)
{
    free(q);
}
bool queue_empty(queue *q)
{
    return q->front == q->rear;
}
bool enQueue(queue *&q, elem e)
{
    if (q->front == ((q->rear + 1) % maxsize))return false;
    q->rear = (q->rear + 1) % maxsize;
    q->data[q->rear] = e;
    return true;
}
bool deQueue(queue *&q, elem &e)
{
    if (q->front == q->rear)return false;
    q->front = (q->front + 1) % maxsize;
    e = q->data[q->front];
    q->data[q->front] = 0;
    return true;
}
void _display(queue *q)
{
    for (int i = 0; i < maxsize; i++)
    {
        cout << q->data[i] << " ";
    } cout << endl;
}
void display(queue *q)
{
    if (q->front == q->rear)return;
    for (int i = q->front + 1; i != (q->rear + 1) % maxsize; i = (i + 1) % maxsize)
    {
        cout << q->data[i] << ' ';
    } cout << endl;
}