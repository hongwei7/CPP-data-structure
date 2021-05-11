#include <dbg.h>
#include <vector>

using namespace std;

//保证最大堆的性质：每一个元素大于其子节点的元素
void adjust(vector<int>& vec, int size){
    for(int i = size - 1; i >= 0; --i){
        if(2 * i + 1 < size && vec[2 * i + 1] > vec[i])
            swap(vec[i], vec[2 * i + 1]);
        if(2 * i < size && vec[2 * i] > vec[i])
            swap(vec[i], vec[2 * i]);
    }
}

void heapSort(vector<int>& vec){
    for(int i = vec.size(); i > 0; --i){
        adjust(vec, i);
        dbg(vec);
        swap(vec[i - 1], vec[0]);
    }
}

int main(){
    vector<int> vec{4, 5, 3, 2, 1};
    heapSort(vec);
    dbg(vec);
}