#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) {
        q.push(i);
    }
    
    cout << '<';
    while(!q.empty()) {
        for(int i = 1; i < K; ++i) {
            q.push(q.front());
            q.pop();
        }
        
        cout << q.front();
        q.pop();
        if(!q.empty()) cout << ", ";
    }
    
    cout << '>';
    return 0;
}