#define max_size 50
typedef int elem;
struct sqlist
{
    elem data[max_size];
    int length;
};//顺序表类型

struct Node
{
    elem data;
    Node * next;
};