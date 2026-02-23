#include <iostream>
#include <vector>
using namespace std;

int N, M, J, K, cnt, ans;
vector<int> graph[1001];
int visit[1001], match[1001];

bool dfs(int A) {
    if(visit[A] == cnt) return false;
    visit[A] = cnt;
    
    for(int B : graph[A]) {
        if(!match[B] || dfs(match[B])) {
            match[B] = A;
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
        ++cnt;
        if(dfs(i)) ++ans;
        ++cnt;
        if(dfs(i)) ++ans;
    }
    
    cout << ans;
    return 0;
}