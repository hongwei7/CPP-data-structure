#include <dbg.h>
#include <vector>

using namespace std;
//leftChild = 2 * i + 1      rightChild = 2 * i + 2

//上浮元素
void insertHeapify(vector<int>& heap){
    int index = heap.size() - 1;
    int elem = heap.back();
    for(int i = (index - 1) / 2; ; i = (i - 1) / 2){
        if(heap[i] > heap[index]){
            swap(heap[i], heap[index]);
            index = i;
        }
        else break;
    }
}

void insert(int elem, vector<int>& heap){
    heap.push_back(elem);
    insertHeapify(heap);
}

//下沉元素
void deleteHeapify(vector<int>& heap){
    int n = heap.size();
    int index = 0;
    int i = 0;
    while(true){
        // dbg(heap);
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if(left < n)i = (heap[i] > heap[left])? left: i;
        if(right < n)i = (heap[i] > heap[right])? right: i;
        // dbg(index, i);
        if(i == index)break;
        swap(heap[i], heap[index]);
        index = i;
    }
}

//交换 root 和最后一个元素，开始下沉元素
int pop(vector<int>& heap){
    if(heap.size() == 0)return -1;
    swap(heap[0], heap[heap.size() - 1]);
    int res = heap.back();
    heap.pop_back();
    deleteHeapify(heap);
    return res;
}

int main(){
    vector<int> heap;
    for(int i: {5, 4, 3, 2, 1})
        insert(i, heap);
    dbg(heap);
    for(int i = 0; i < 5; ++i)
        dbg(pop(heap));
}