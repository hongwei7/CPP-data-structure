#include<iostream>
using namespace std;
#include "Glist.h"
void fun(GlistNode * g)
{
    if(g!=NULL)
    {
        if(g->tag==1)
            fun(g->val.sublist);
        else
            //function here
            cout<<g->val.data<<" ";
            //function here
        fun(g->link);
    }
}
int Glst_length(GlistNode *g)
{
    int n=0;
    GlistNode *gi;
    gi=g->val.sublist;
    while(gi!=NULL)
    {
        gi=gi->link;
        n++;
    }
    return n;
}
int GlistNode_depth(GlistNode * g)
{
    int depth;GlistNode *gi;
    int max=0;
    if(g->tag==0)return 0;
    if(g->val.sublist==NULL)return 1;
    gi=g;
    while(gi!=NULL)
    {
        if(gi->tag==1)
        {
            depth=GlistNode_depth(gi);
            if(depth>max)
                max=depth;
        }
        gi=gi->link;
    }
    return max+1;
}
bool same(GlistNode *g1,GlistNode *g2)
{
    while(g1->link!=NULL)
    {
        if(g1->tag==1)
            if(g2->tag==1)
                return same(g1->val.sublist,g2->val.sublist)&&same(g1->link,g2->link);
            else
                return false;
        else
            if(g1->val.data!=g2->val.data)
                return false;
        return same(g1->link,g2->link);
    }
    if(g2->link==NULL)return true;
    else return false;
}
void print(GlistNode *g)
{
    cout<<'(';
    if(g!=NULL)
    {
        if(g->tag==1)
        {
            cout<<"(";
            print(g->val.sublist);
            cout<<")";
        }
        else
            //function here
            cout<<g->val.data<<" ";
            //function here
        cout<<',';
        print(g->link);
    }
    cout<<')';
}
int main()
{

}