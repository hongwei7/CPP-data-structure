#include<iostream>
using namespace std;
typedef int elem;
#define max_size 50
struct stack
{
    elem data[max_size];
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
bool push(stack *& s,elem e)
{
    if(s->top>=max_size-1)return false;
    s->top++;
    s->data[s->top]=e;
    return true;
}
bool pop(stack *& s,elem & e)
{
    if(s->top==-1)return false;
    e=s->data[s->top--];
    return true;
}
bool Get_top(stack * s,elem &e)
{
    if(s->top==-1)return false;
    e=s->data[s->top];
    return true;
}
void Disp_stack(stack *s)
{
    for(int i=0;i<=s->top;i++)
    {
        cout<<s->data[i]<<" ";
    }cout<<endl;
}
bool match(char exp[])
{
    stack *s;
    Init_stack(s);
    elem e,q;
    bool is_match=true;
    for(int i=0;exp[i]!='\0';i++)
    {
        e=exp[i];
        if(e=='('||e=='['||e=='{')
            push(s,e);
        else if(e==')'||e==']'||e=='}')
        {
            if(pop(s,q)==false)is_match=false;
            if(e-q>3||e-q<1)is_match=false;
        }
    }
    if(!Stack_empty(s))is_match=false;
    Destroy_stack(s);
    return is_match;
}
bool check(char a[])
{
    int i=0,top=-1;
    bool legal=true;
    while(a[i]!='\0')
    {
        if(a[i]=='I')
        {
            top++;
            if(top<-1||top>max_size)legal=false;
        }
        if(a[i]=='O')
        {
            top--;
            if(top<-1||top>max_size)legal=false;
        }
        i++;
    }
    return legal;
}
void trans(char *exp,char *postexp)//后缀表达式
{
    elem e;
    stack *Optr;
    Init_stack(Optr);
    int i=0;
    while(*exp!='\0')
    {        
        switch(*exp)
        {
            case '(':
                push(Optr,'(');
                exp++;
                break;
            case ')':
                pop(Optr,e);
                while(e!='(')
                {
                    postexp[i++]=e;
                    pop(Optr,e);
                }
                exp++;
                break;
            case '+':
            case '-':
            while(!Stack_empty(Optr))
            {
                Get_top(Optr,e);
                if(e!='(')
                {
                    postexp[i++]=e;
                    pop(Optr,e);
                }
                else break;
            }
            push(Optr,*exp);
            exp++;
            break;
            case '*':
            case '/':
            while(!Stack_empty(Optr))
            {
                Get_top(Optr,e);
                if(e=='*'||e=='/')
                {
                    postexp[i++]=e;
                    pop(Optr,e);
                }
                else break;
            }
            push(Optr,*exp);
            exp++;
            break;
            default:
            while(*exp>='0'&&*exp<='9')
            {
                postexp[i++]=*exp;
                exp++;
            }
            postexp[i++]='#';
        }
    }
    while(!Stack_empty(Optr))
    {
        pop(Optr,e);
        postexp[i++]=e;
    }
    postexp[i]='\0';
    Destroy_stack(Optr);
    
}

int main()
{
    stack *stack_1;
    elem e;
    Init_stack(stack_1);
    push(stack_1,14);
    push(stack_1,32);
    push(stack_1,81);
    push(stack_1,59);
    push(stack_1,'s');
    Disp_stack(stack_1);
    cout<<"e="<<e<<endl;
    pop(stack_1,e);
    cout<<"e=pop()"<<endl;
    Disp_stack(stack_1);
    cout<<"e="<<e<<endl;
    Get_top(stack_1,e);
    cout<<"e=Get_top()"<<endl;
    Disp_stack(stack_1);
    cout<<"e="<<e<<endl;
    Destroy_stack(stack_1);
    Disp_stack(stack_1);
    char exp[]="(56-20)/(4+2)";
    char postexp[20]="";
    if(match(exp))cout<<"expression is match."<<endl;
    else cout<<"expression not match."<<endl;
    cout<<"exp: "<<exp<<endl;
    trans(exp,postexp);
    cout<<"out: "<<postexp<<endl;
    char a[]="IIIOOIOO";
    cout<<check(a)<<endl;
}