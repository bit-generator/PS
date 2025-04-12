#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int A[1'000'000];
vector<int> v, LISidx, LIS;
int parent[1'000'000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> A[i];
    
    memset(parent, -1, sizeof(int) * N);
    for(int i = 0; i < N; ++i) {
        auto it = lower_bound(v.begin(), v.end(), A[i]);
        int idx = it - v.begin();
        
        if(it == v.end()) {
            v.push_back(A[i]);
            LISidx.push_back(i);
        }
        else {
            *it = A[i];
            LISidx[idx] = i;
        }

        if(idx > 0) {
            parent[i] = LISidx[idx - 1];
        }
    }
    
    int idx = LISidx[LISidx.size() - 1];
    while(idx != -1) {
        LIS.push_back(A[idx]);
        idx = parent[idx];
    }
    
    cout << LIS.size() << '\n';
    for(int i = LIS.size() - 1; i >= 0; --i) cout << LIS[i] << ' ';
    return 0;
}