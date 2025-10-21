#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cstring>
using namespace std;

constexpr size_t MAX_SIZE = 500000;
int N, M, S, P, X, idCnt;
int path[MAX_SIZE][2];
int money[MAX_SIZE + 1];
vector<int> graph[MAX_SIZE + 1];
unordered_set<int> newgraph[MAX_SIZE + 1];
vector<int> st;
bool fin[MAX_SIZE + 1], isDiner[MAX_SIZE + 1];
int id[MAX_SIZE + 1], parent[MAX_SIZE + 1];
int maxMoney[MAX_SIZE + 1];

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
            
            parent[tmp] = cur;
            isDiner[cur] |= isDiner[tmp];
            fin[tmp] = true;
            if(tmp == cur) break;
            money[cur] += money[tmp];
        }
    }
    
    return p;
}

int newdfs(int cur) {
    if(maxMoney[cur] != -1) return maxMoney[cur];
    int ret = 0;
    
    for(int nxt : newgraph[cur]) {
        ret = max(ret, newdfs(nxt));
    }
    
    if(ret == 0 && !isDiner[cur]) return 0;
    return maxMoney[cur] = money[cur] + ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        cin >> path[i][0] >> path[i][1];
        graph[path[i][0]].push_back(path[i][1]);
    }
    
    for(int i = 1; i <= N; ++i) cin >> money[i];
    cin >> S >> P;
    while(P--) {
        cin >> X;
        isDiner[X] = true;
    }
    
    for(int i = 1; i <= N; ++i) {
        if(fin[i]) continue;
        dfs(i);
    }
    
    for(int i = 0; i < M; ++i) {
        int a = parent[path[i][0]];
        int b = parent[path[i][1]];
        if(a == b) continue;
        
        newgraph[a].insert(b);
    }
    
    memset(maxMoney, -1, sizeof(int) * (N + 1));
    cout << newdfs(parent[S]);
    return 0;
}