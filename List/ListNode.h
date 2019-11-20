#define max_size 50
typedef int elem;
struct sqlist
{
    elem data[max_size];
    int length;
};
struct Node
{
    elem data;
    Node * next;
};