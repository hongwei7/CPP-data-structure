#include <dbg.h>
#include <vector>

using namespace std;

void insertSort(vector<int>& v) {
    for(int i = 0; i < v.size(); ++i) {
        int maxIndex = 0;
        for(int j = 1; j < v.size() - i; ++j) {
            if(v[maxIndex] < v[j]) {
                maxIndex = j;
            }
        }
        swap(v[maxIndex], v[v.size() - i - 1]);
    }
}

int main() {
    vector<int> v{5, 4, 3, 2, 1};
    insertSort(v);
    dbg(v);
}