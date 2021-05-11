#include <dbg.h>
#include <vector>

using namespace std;

void quickSort(vector<int>& vec, int left, int right){
    if(left >= right)return;
    dbg(vec);
    int l = left, r = right;
    int baseLine = vec[left];
    while(l < r){
        while(l < r && vec[r] >= baseLine) --r;
        while(l < r && vec[l] <= baseLine) ++l;
        swap(vec[l], vec[r]);
    }
    swap(vec[left], vec[l]);
    quickSort(vec, left, l - 1);
    quickSort(vec, l + 1, right);
}

int main(){
    vector<int> vec{5, 4, 3, 2, 1};
    quickSort(vec, 0, vec.size() - 1);
    dbg(vec);
}