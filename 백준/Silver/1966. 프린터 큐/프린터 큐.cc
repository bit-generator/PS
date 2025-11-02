#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int T, N, M, K, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        ans = 0;
        
        cin >> N >> M;
        for(int i = 0; i < N; ++i) {
            cin >> K;
            q.emplace(K, i);
            pq.push(K);
        }
        
        while(!q.empty()) {
            auto x = q.front();
            q.pop();
            
            if(x.first == pq.top()) {
                pq.pop();
                ++ans;
                if(x.second == M) break;
            }
            else {
                q.push(x);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}