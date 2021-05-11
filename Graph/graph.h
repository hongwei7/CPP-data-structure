#define MAXV 30
#define INF 32767
#define MaxSize 1000
struct InfoType
{
    elem data;
};
struct ArcNode
{
    int adjvex;
    ArcNode * next;
    double weight;
};
struct VNode
{
    InfoType info;
    ArcNode * firstarc;
};
struct AdjGraph
{
    VNode adjlist[MAXV];
    int n,e;
};

struct VertexType
{
    int no;
    InfoType info;
};
struct MatGraph
{
    int edges[MAXV][MAXV];
    int n,e;
    VertexType vexs[MAXV];
};