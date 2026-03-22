#include <iostream>
#include <deque>
using namespace std;

int N, B, M, C;
int A[100000];
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) {
        cin >> B;
        if(!A[i]) dq.push_back(B);
    }
    
    cin >> M;
    while(M--) {
        cin >> C;
        dq.push_front(C);
        C = dq.back();
        dq.pop_back();
        cout << C << ' ';
    }
    
    return 0;
}