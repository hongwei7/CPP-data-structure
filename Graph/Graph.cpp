#include <stdio.h>
#define elem int
#include "graph.h"
#include<algorithm>
void CreateAdj_bymatrix(AdjGraph *&G, int A[MAXV][MAXV], int n, int e)
{
    int i, j;
    ArcNode *p;
    G = new AdjGraph;
    for (i = 0; i < n; i++) {
        G->adjlist[i].firstarc = NULL;
    }
    for (i = 0; i < n; i++) {
        for (j = n - 1; j >= 0; j--) {
            if (A[i][j] != 0 && A[i][j] != INF) {
                p = new ArcNode;
                p->adjvex = j;
                p->weight = A[i][j];
                p->next = G->adjlist[i].firstarc;
                G->adjlist[i].firstarc = p;
            }
        }
    }
    G->n = n; G->e = e;
}
void DispAdj(AdjGraph *G)
{ 
    int i; ArcNode *p;
    for (i = 0; i < G->n; i++) {
        p = G->adjlist->firstarc;
        printf("%3d:", i);
        while (p != NULL) {
            printf("%3f[%d]->", p->weight, p->adjvex);
            p = p->next;
        }
        printf("^\n");
    }
}
#include<iostream>
void DestroyAdj(AdjGraph *&G)
{
    int i; ArcNode *pre, *p;
    for (int i = 0; i < G->n; i++)
    {
        pre = G->adjlist[i].firstarc;
        if (pre != NULL) {
            p = pre->next;
            while (p != NULL)
            {
                free(pre);
                pre = p;
                p = p->next;
            }
        }
    }
    free(G);
}
void ListToMat(AdjGraph *G, MatGraph &g)
{
    int i;
    ArcNode *p;
    for (i = 0; i < G->n; i++) {
        p = G->adjlist[i].firstarc;
        while (p != NULL) {
            g.edges[i][p->adjvex] = p->weight;
            p = p->next;
        }
    }
    g.e = G->e; g.n = G->n;
}

#define MAX 50
//深度优先遍历
int visited[MAX] = {0};
void DFS(AdjGraph * G, int v)
{
    ArcNode *p;
    visited[v] = 1;
    printf("%d", v);
    p = G->adjlist[v].firstarc;
    while (p != NULL) {
        if (visited[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->next;
    }
}



//广度优先遍历
#include "queue.h"
void BFS(AdjGraph *G, int v)
{
    int w, i;
    ArcNode *p;
    queue *qu;
    Init_queue(qu);
    int visitedB[MAX];
    for (i = 0; i < G->n; i++)
        visitedB[i] = 0;
    printf("%2d", v);
    visitedB[v] = 1;
    enQueue(qu, v);
    while (!queue_empty(qu)) {
        deQueue(qu, w);
        p = G->adjlist[w].firstarc;
        while (p != NULL) {
            if (visitedB[p->adjvex] == 0) {
                printf("%2d", p->adjvex);
                visitedB[p->adjvex] = 1;
                enQueue(qu, p->adjvex);
            }
            p = p->next;
        }
    }
    printf("\n");
}

static int path[MAXV]={0};
void FindAllPath(AdjGraph *G,int u,int v,int d)
{
    int w,i;ArcNode *p;
    d++;path[d]=u;
    visited[u]=1;
    if(u==v&&d>=0)
    {
        for(i=0;i<=d;i++)
        {
            printf("%2d",path[i]);
        }
        printf("\n");
    }
    p=G->adjlist[u].firstarc;
    while(p!=NULL)
    {
        w=p->adjvex;
        if(visited[w]==0)
            FindAllPath(G,w,v,d);
        p=p->next;
    }
    visited[u]=0;
} 

void Prim(MatGraph g,int v)
{
    int lowcost[MAXV];
    int MIN;
    int closest[MAXV],i,j,k;
    for (i = 0; i < g.n; ++i)
    {
        lowcost[i]=g.edges[v][i];
        closest[i]=v;
    }
    for(i=1;i<g.n;i++)
    {
        MIN=INF;
        for(j=0;j<g.n;j++)
        {
            if(lowcost[j]!=0&&lowcost[j]<MIN)
            {
                MIN=lowcost[j];
                k=j;
            }
        }
        printf("边(%d,%d)权为:%d\n",closest[k],k,MIN );
        lowcost[k]=0;
        for(j=0;j<g.n;j++)
        {
            if(lowcost[j]!=0&&g.edges[k][j]<lowcost[j])
            {
                lowcost[j]=g.edges[k][j];
                closest[j]=k;
            }
        }
    }
}

struct Edge
{
    int u,v,w;
};
void Esort(Edge E[],int n)
{
    Edge e;
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(E[j].w>E[j+1].w){
                e=E[j];
                E[j]=E[j+1];
                E[j+1]=e;
            }
        }
    }
}
void Kruskal(MatGraph g)
{
    int i,j,u1,v1,sn1,sn2,k;
    int vset[MAXV];
    Edge E[MaxSize];
    k=0;
    for(i=0;i<g.n;i++)
        for(j=0;j<=i;j++)
            if(g.edges[i][j]!=0&&g.edges[i][j]!=INF)
            {
                E[k].u=i;E[k].v=j;E[k].w=g.edges[i][j];
                k++;
            }
    Esort(E,g.e);
    for(i=0;i<g.n;i++)
        vset[i]=i;
    k=1;
    j=0;
    while(k<g.n)
    {
        u1=E[j].u;v1=E[j].v;
        sn1=vset[u1];
        sn2=vset[v1];
        if(sn1!=sn2)
        {
            printf(" (%d,%d):%d\n",u1,v1,E[j].w );
            k++;
            for (i = 0; i < g.n; ++i)
            {
                if(vset[i]==sn2)
                    vset[i]=sn1;
            }
        }
        j++;
    }
}
void cal_in_out(AdjGraph *G,int in[],int out[],int &zero_out)//计算点的入度、出度、出度为零的点个数
{
    ArcNode * p;
    for(int i=0;i<G->n;i++)
    {
        in[i]=0;
        out[i]=0;
    }
    zero_out=0;
    for(int i=0;i<G->n;i++)
    {
        p=G->adjlist[i].firstarc;
        for(int j=0;j<G->n&&p!=NULL;j++)
        {
            out[i]++;
            in[j]++;
            p=p->next;
        }
        if(out[i]==0)
            zero_out++;
    }
}

int main()
{

}









