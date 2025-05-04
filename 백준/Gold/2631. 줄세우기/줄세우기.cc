#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> M;
        auto it = lower_bound(v.begin(), v.end(), M);
        if(it == v.end()) {
            v.push_back(M);
        }
        else {
            *it = M;
        }
    }
    
    cout << N - v.size();
    return 0;
}