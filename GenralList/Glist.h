typedef int elem;

struct GlistNode
{
    int tag;
    union
    {
        elem data;
        GlistNode * sublist;
    }val;
    GlistNode * link;
};