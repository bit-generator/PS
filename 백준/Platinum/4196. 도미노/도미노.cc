#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int T, N, M, x, y, idCnt, ans;
int relation[100000][2];
vector<int> graph[100001];
vector<int> st;
int id[100001];
bool fin[100001];
int parent[100001];
int indegree[100001];
bool check[100001];

int dfs(int cur) {
    st.push_back(cur);
    id[cur] = ++idCnt;
    
    int p = id[cur];
    for(int nxt : graph[cur]) {
        if(id[nxt] == 0) p = min(p, dfs(nxt));
        else if(!fin[nxt]) p = min(p, id[nxt]);
    }
    
    if(p == id[cur]) {
        while(!st.empty()) {
            int tmp = st.back();
            st.pop_back();
            
            fin[tmp] = true;
            parent[tmp] = cur;
            if(tmp == cur) break;
        }
    }
    
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N >> M;
        
        idCnt = 0; ans = 0;
        memset(id, 0, sizeof(id));
        memset(fin, 0, sizeof(fin));
        memset(indegree, 0, sizeof(indegree));
        memset(check, 0, sizeof(check));
        for(int i = 1; i <= N; ++i) {
            graph[i].clear();
        }
        
        for(int i = 0; i < M; ++i) {
            cin >> relation[i][0] >> relation[i][1];
            graph[relation[i][0]].push_back(relation[i][1]);
        }
        
        for(int i = 1; i <= N; ++i) {
            if(fin[i]) continue;
            dfs(i);
        }
        
        for(int i = 0; i < M; ++i) {
            int a = parent[relation[i][0]];
            int b = parent[relation[i][1]];
            if(a == b) continue;
            ++indegree[b];
        }
        
        for(int i = 1; i <= N; ++i) {
            int tmp = parent[i];
            if(!indegree[tmp] && !check[tmp]) {
                ++ans;
                check[tmp] = true;
            } 
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}