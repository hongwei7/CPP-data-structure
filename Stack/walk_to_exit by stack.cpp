#include <iostream>/*使用栈*/
using namespace std;
int mapdata[10][10]=
    {
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,1,0,0,0,1,0,1},
        {1,0,0,0,0,1,1,0,0,1},
        {1,0,1,1,1,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
        {1,0,1,0,0,0,1,0,0,1},
        {1,0,1,1,1,0,1,1,0,1},
        {1,1,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
    };
struct mymap
{
    static const int entry_i=1,entry_j=1;
    static const int exit_i=1,exit_j=8;
    int mapdata[10][10];
    mymap(int data[10][10])
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                mapdata[i][j]=data[i][j];
            }
        }
    }
    void display_this(int e)
    {
        switch(e)
        {
        case 0:cout<<"   ";return;
        case 1:cout<<"[X]";return;
        case 2:cout<<" # ";return;
        }
    }
    void display(int player_i,int player_j,int steps)
    {   for(int i=0;i<15;i++)cout<<endl;
        cout<<" player location:("<<player_i<<','<<player_j<<")"<<" steps:"<<steps<<endl;
        for(int i=0;i<3;i++)cout<<endl;
        cout<<"|------------------------------|"<<endl<<'|';
        for(int i=0;i<player_i;i++)
        {
            for(int j=0;j<10;j++)
            {
                display_this(mapdata[i][j]);
            }cout<<'|'<<endl<<'|';
        }
        for(int j=0;j<player_j;j++)
        {
            display_this(mapdata[player_i][j]);
        }
        cout<<" P ";
        for(int j=player_j+1;j<10;j++)
        {
            display_this(mapdata[player_i][j]);
        }cout<<'|'<<endl<<'|';
        for(int i=player_i+1;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                display_this(mapdata[i][j]);
            }cout<<'|'<<endl<<'|';
        }
        cout<<"------------------------------|"<<endl;
        for(int i=0;i<7;i++)cout<<endl;
        system("sleep .1");
    }
};

struct player_state
{
    int i,j,di;
};
#define max_size 50
struct stack
{
    player_state data[max_size];
    int top;
};
void Init_stack(stack *& s)
{
    s=new stack;
    s->top=-1;
}
void Destroy_stack(stack *& s)
{
    free(s);
}
bool Stack_empty(stack * s)
{
    return s->top==-1;
}
bool push(stack *& s,player_state e)
{
    if(s->top>=max_size-1)return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}
bool pop(stack *& s,player_state *& e)
{
    if(s->top==-1)return false;
    e=&(s->data[s->top--]);
    return true;
}
bool Get_top(stack * s,player_state *e)
{
    if(s->top==-1)return false;
    e=&(s->data[s->top]);
    return true;
}
void edit_state(player_state *man ,int i,int j,int di)
{
    man->i=i;
    man->j=j;
    man->di=di;
}
bool walk_to_exit(mymap *target_map)
{
    stack *path=new stack;
    Init_stack(path);
    int i1,j1,steps=0;
    player_state *man=new player_state();
    edit_state(man,target_map->entry_i,target_map->entry_j,0);
    target_map->mapdata[target_map->entry_i][target_map->entry_j]=2;
    while(man->i!=target_map->exit_i||man->j!=target_map->exit_j)
    {
        steps++;
        switch(man->di)
        {
            case 0:i1=man->i;j1=man->j+1;break;
            case 1:i1=man->i+1;j1=man->j;break;
            case 2:i1=man->i;j1=man->j-1;break;
            case 3:i1=man->i-1;j1=man->j;break;
            default:target_map->mapdata[man->i][man->j]=0;pop(path,man);man->di++;continue;
        }
        if(target_map->mapdata[i1][j1]==0)
        {
            push(path,*man);
            target_map->mapdata[i1][j1]=2;
            man=new player_state();
            edit_state(man,i1,j1,0);
        }
        else
        {
            man->di++;
            steps--;
        }
        target_map->display(man->i,man->j,steps);
        if(Stack_empty(path))return false;
    }
    Destroy_stack(path);
    return true;
}

int main()
{
    mymap *map1=new mymap(mapdata);
    if(walk_to_exit(map1))cout<<"successfully walk to exit!!"<<endl;
    else cout<<"walk to exit failed!!"<<endl;
}