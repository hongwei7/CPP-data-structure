#include <dbg.h>
#include <vector>

using namespace std;

vector<int> merge(vector<int> v1, vector<int> v2){
    dbg(v1, v2);
    vector<int> res;
    int left = 0, right = 0;
    while(left != v1.size() && right != v2.size()){
        if(v1[left] < v2[right]) res.push_back(v1[left++]);
        else res.push_back(v2[right++]);
    }
    if(left == v1.size()){
        while(right != v2.size()) res.push_back(v2[right++]);
    }
    else {
        while(left != v1.size()) res.push_back(v1[left++]);
    }
    return res;
}

vector<int> mergeSort(vector<int> vec){
    if(vec.size() <= 1)return vec;
    dbg(vec);
    int mid = vec.size() / 2;
    vector<int> left = mergeSort(vector<int>(vec.begin(), vec.begin() + mid));
    vector<int> right = mergeSort(vector<int>(vec.begin() + mid, vec.end()));

    return merge(left, right);
}

int main(){
    vector<int> vec{5, 4, 3, 2, 1};
    vector<int> sortedVec = mergeSort(vec);
    dbg(sortedVec);
}