#include <iostream>
using namespace std;
struct queen
{
    int i,j;
};
struct stack
{
    queen * q[8];
    int top;
};
bool check(stack *s,queen *q)
{
    double k=0;
    for(int i=0;i<s->top;i++)
    {    
         if(s->q[i]->i==q->i||q->j==s->q[i]->j)
            {
                //cout<<"not match:"<<q->i<<" "<<q->j<<" vs "<<s->q[i]->i<<" "<<s->q[i]->j<<endl;
                return false;
            }
         k=(double((s->q[i]->i)-(q->i)))/(double((s->q[i]->j)-(q->j)));
         if(k==1||k==-1)
         {
            //cout<<"not match:"<<q->i<<" "<<q->j<<" vs "<<s->q[i]->i<<" "<<s->q[i]->j<<"  k="<<k<<endl;
            return false;
        }
    }
    return true;
}
void display(int map[8][8],stack* s)
{
    cout<<"***** graph ******"<<endl;
    for(int i=0;i<s->top;i++)
    {
        //cout<<"stack ["<<i<<"]: "<<s->q[i]->i<<" "<<s->q[i]->j<<endl;
        map[s->q[i]->i][s->q[i]->j]=1;
    }
    for(int i=0;i<8;i++)
    {   cout<<" ";
        for(int j=0;j<8;j++)
        {
          if(map[i][j])cout<<"X ";
          else cout<<"O ";
        }cout<<endl;
    }
    cout<<"******************"<<endl;
}
int eightqueen()
{
    int map[8][8];
    for(int i=0;i<8;i++)
    {
       for(int j=0;j<8;j++)
       { map[i][j]=0;}
    }
    queen *q=new queen;
    q->i=0;q->j=0;
    int l;
    stack * s =new stack;
    s->top=0;
    while(!(q->i==8))
    {
        if(q->i==0&q->j==8){return 0;}
        cout<<"check: "<<q->i<<" "<<q->j<<endl;
        if(q->j<8&&check(s,q))
        {
            s->q[s->top++]=q;
            cout<<endl<<"->in: "<<q->i<<" "<<q->j<<endl;
            display(map,s);
            l = q->i+1;
            q =new queen;
            q->i=l;q->j=0;
        }
        else if(q->j<7)q->j++;
        else
        {
            s->top--;
            q=(s->q[s->top]);
            cout<<endl<<"->out: "<<q->i<<" "<<q->j<<endl;
            map[q->i][q->j]=0;
            display(map,s);
            q->j++;
        }        
    }
    return 1;
}
int main()
{
    if(eightqueen())cout<<"success!";
    else cout<<"failed!";
}

