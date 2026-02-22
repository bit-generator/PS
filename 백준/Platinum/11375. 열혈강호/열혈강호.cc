#include <iostream>
#include <vector>
using namespace std;

int N, M, J, K, ans, curNode;
vector<int> graph[1001];
int visit[1001];
int match[1001];

bool dfs(int nodeA) {
    for(int nodeB : graph[nodeA]) {
        if(visit[nodeB] == curNode) continue;
        visit[nodeB] = curNode;
        
        if(!match[nodeB] || dfs(match[nodeB])) {
            match[nodeB] = nodeA;
            return true;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        cin >> K;
        while(K--) {
            cin >> J;
            graph[i].push_back(J);
        }
    }
    
    for(int i = 1; i <= N; ++i) {
        curNode = i;
        if(dfs(i)) ++ans;
    }
    
    cout << ans;
    return 0;
}