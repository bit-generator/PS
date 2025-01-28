#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, A, B;
vector<int> graph[32001];
int indegree[32001];
priority_queue<int, vector<int>, greater<>> pq;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B;
        graph[A].push_back(B);
        ++indegree[B];
    }
    
    for(int i = 1; i <= N; ++i) {
        if(!indegree[i]) pq.push(i);
    }
    
    while(!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);
        
        for(int nxt : graph[cur]) {
            if(!(--indegree[nxt])) {
                pq.push(nxt);
            }
        }
    }
    
    for(int i : ans) cout << i << ' ';
    return 0;
}