#include<iostream>
using namespace std;
#define maxsize 30 
#include "string.h"
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
void Destroy_str(mystring &s)
{}
void Str_copy(mystring &s,mystring t)
{
    for(int i=0;i<t.length;i++)
    {
        s.data[i]=t.data[i];
    }
    s.length=t.length;
}
bool Str_equal(mystring s1,mystring s2)
{
    if(s1.length!=s2.length)return false;
    for(int i=0;i<s1.length;i++)
    {
        if(s1.data[i]!=s2.data[i])return false;
    }
    return true;
}
int Str_length(mystring s)
{
    return s.length;
}
mystring Concat(mystring s1,mystring s2)
{
    mystring result;
    Str_copy(result,s1);
    for(int i=0;i<s2.length;i++)
    {   
        result.data[i+s1.length]=s2.data[i];
    }
    result.length+=s2.length;
    return result;
}
mystring SubStr(mystring s,int i,int j)
{
    mystring result;
    if(j<i||j>s.length||i<1)return result;
    int t;
    for(t=i-1;t<j;t++)
    {
        result.data[t-i+1]=s.data[t];
    }
    result.length=t;
    return result;
}
void Display(mystring s)
{
    for(int i=0;i<s.length;i++)
    {
        cout<<s.data[i];
    }
    cout<<endl;
}
mystring str_and_str(mystring s1,mystring s2)
{
    mystring s3;
    s3.length=0;
    for(int i=0;i<s1.length;i++)
    {
        if(s3.length!=0&&s1.data[i]==s3.data[s3.length-1])continue;
        for(int j=0;j<s2.length;j++)
        {
            if((s1.data[i]==s2.data[j])&&s3.length<maxsize)
            {
                s3.data[s3.length++]=s1.data[i];
                break;
            }
        }
    }
    return s3;
}
int main()
{
    mystring s1,s2,s3;
    char hello[]="hello world";
    char jack[]="hokkkrlkkkekkk";
    Str_assign(s1,hello);
    Str_assign(s2,jack);
    Display(s1);
    Display(s2);
    /*
    Str_copy(s3,s1);
    Display(s3);
    cout<<Str_equal(s1,s3)<<endl;
    Display(Concat(s3,s1));
    Display(SubStr(s3,3,7));
    */
    Display(str_and_str(s2,s1));
    return 0;
}