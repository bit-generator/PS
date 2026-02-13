#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, A, ans;
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> A;
        pq.push(A);
    }
    
    while(pq.size() > 1) {
        int n1 = pq.top();
        pq.pop();
        int n2 = pq.top();
        pq.pop();
        
        ans += n2;
        if(n1 - n2 > 0) pq.push(n1 - n2);
    }
    
    if(!pq.empty()) ans += pq.top();
    if(ans > 1440) cout << -1;
    else cout << ans;
    return 0;
}