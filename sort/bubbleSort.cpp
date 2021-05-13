#include <dbg.h>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& v) {
    for(int i = v.size(); i >= 0; --i) {
        for(int j = 0; j < i - 1; ++j) {
            if(v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1};
    bubbleSort(v);
    dbg(v);
}