#include <stdio.h>
#include "HashMap.h"
#include <iostream>
void InsertHT(HashTable ha[],int &n,int m,int p,KeyType k)
{
    int i,adr;
    adr=k%p;
    if(ha[adr].key==NULLKEY||ha[adr].key==DELKEY){
        ha[adr].key=k;
        ha[adr].count=1;
    }
    else{
        i=1;
        do{    //线性检测
            adr=(adr+1) % m;
            i++;
        }while(ha[adr].key!=NULLKEY && ha[adr].key!=DELKEY);
        ha[adr].key=k;
        ha[adr].count=i;
    }
}
void CreateHT(HashTable ha[],int &n,int m,int p,KeyType keys[],int n1)
{
    for(int i=0;i<m;i++)
    {
        ha[i].key=NULLKEY;
        ha[i].count=0;
    }
    n=0;
    for(int i=0;i<n1;i++){
        InsertHT(ha,n,m,p,keys[i]);
    }
}
bool DeleteHT(HashTable ha[],int &n ,int m,int p,KeyType k)
{
    int adr;
    adr=k%p;
    while(ha[adr].key!=NULLKEY && ha[adr].key!=k){
        adr=(adr+1) % m;
    }
    if(ha[adr].key==k){
        ha[adr].key=DELKEY;
        return true;
    }
    else
        return false;
}
void SearchHT(HashTable ha[],int m, int p ,KeyType k)
{
    int i=1,adr;
    adr=k%p;
    if(ha[adr].key!=NULLKEY && ha[adr].key!=k){
        i++;
        adr=(adr+1)%m;
    }
    if(ha[adr].key==k)
        printf("成功：关键字:%d 比较:%d 次\n", k,i);
    else
        printf("失败：关键字:%d 比较:%d 次\n", k,i);
}
int main()
{
    
    int n=7;
    int m=1000;
    int p=20;
    HashTable t1[m];
    KeyType keys[]={23,15,35,43,64,345,2};
    CreateHT(t1,n,m,p,keys,7);
    printf("%d\n", DeleteHT(t1,n,m,p,15));
    for(int i=0;i<7;i++)
        SearchHT(t1,m,p,keys[i]);

}