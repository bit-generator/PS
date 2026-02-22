#include <iostream>
#include <unordered_set>
using namespace std;

int nA, nB, N;
unordered_set<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> nA >> nB;
    for(int i = 0; i < nA; ++i) {
        cin >> N;
        A.insert(N);
    }
    
    for(int i = 0; i < nB; ++i) {
        cin >> N;
        B.insert(N);
    }
    
    N = 0;
    for(const auto& n : A) {
        if(B.find(n) != B.end()) ++N;
    }
    
    cout << nA + nB - (N << 1);
    return 0;
}