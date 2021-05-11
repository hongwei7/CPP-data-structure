#define NULLKEY -1
#define DELKEY -2
#define KeyType int
struct HashTable
{
    KeyType key;//key值
    int count;//冲突次数
};