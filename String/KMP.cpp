#include<iostream>
using namespace std;
#define maxsize 30 
struct mystring
{
    char data[maxsize];
    int length;
};
void Init_str(mystring &s)
{
    s.length=0;
}
void Str_assign(mystring & s,char cstr[])
{
    int i=0;
    for(;*cstr!='\0';i++)
    {
        s.data[i]=*cstr++;
    }
    s.length=i;
}

void Display(mystring s)
{
    for(int i=0;i<s.length;i++)
    {
        cout<<s.data[i];
    }
    cout<<endl;
}
int caluculate_next(mystring s,int i)
{
    int head=0,result=0;
    while(head<=i-1)
    {
        for(int k=0;k<=head;k++)
        {
            //cout<<"s["<<k<<"]: "<<s.data[k]<<" "<<"s["<<i-1-head+k<<"]: "<<s.data[i-1-head+k]<<endl;
            if(s.data[k]!=s.data[i-1-head+k])
                {
                    result--;
                    break;
                }
        }
        result++;
        head++;
    }return result;
}
int KMP(mystring s,mystring t)
{
    int next[s.length];
    next[0]=-1;
    next[1]=0;
    for(int i=2;i<s.length;i++)
    {
        next[i]=caluculate_next(s,i);
    }
    int i=0,j=0;
    while(i<s.length&&j<t.length)
    {
        if(i==-1||s.data[i]==t.data[j])
        {
            i++;
            j++;
        }
        else
            i=next[i];
    }
    if(i>=s.length)return j-s.length;
    else return -1;
}
int imporved_KMP(mystring s,mystring t)
{
    int next[s.length],nextval[s.length];
    next[0]=-1;
    next[1]=0;
    for(int i=2;i<s.length;i++)
    {
        next[i]=caluculate_next(s,i);
    }
    nextval[0]=-1;
    for(int i=1;i<s.length;i++)
    {
        if(s.data[i]==s.data[next[i]])nextval[i]=nextval[next[i]];
        else nextval[i]=next[i];
    }
    int i=0,j=0;
    while(i<s.length&&j<t.length)
    {
        if(i==-1||s.data[i]==t.data[j])
        {
            i++;
            j++;
        }
        else
            i=next[i];
    }
    if(i>=s.length)return j-s.length;
    else return -1;
}
int main()
{
    char ss[]="abcabaa",tt[]="abcaabbabcabaacbacba";
    mystring s,t;   
    Init_str(s);
    Init_str(t);
    Str_assign(s,ss);
    Str_assign(t,tt);
    //Display(s);
    //cout<<caluculate_next(s,5);
    cout<<KMP(s,t)<<endl;
    cout<<imporved_KMP(s,t)<<endl;
    return 0;
}



