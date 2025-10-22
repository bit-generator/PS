#include <iostream>
#include <vector>
#include <algorithm>
#define OFFSET    100'000
using namespace std;

int N, M, A, B, idCnt;
vector<int> graph[200001];
vector<int> st;
int id[200001], parent[200001];
bool fin[200001];

int dfs(int cur) {
    id[cur] = ++idCnt;
    st.push_back(cur);
    
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
            fin[tmp] = true;
            if(tmp == cur) break;
        }
    }
    
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> A >> B;
        graph[A * (-1) + OFFSET].push_back(B + OFFSET);
        graph[B * (-1) + OFFSET].push_back(A + OFFSET);
    }
    
    for(int i = N * (-1) + OFFSET; i <= N + OFFSET; ++i) {
        if(fin[i]) continue;
        dfs(i);
    }
    
    for(int i = 1; i <= N; ++i) {
        if(parent[i + OFFSET] == parent[i * (-1) + OFFSET]) {
            cout << 0;
            return 0;
        }
    }
    
    cout << 1;
    return 0;
}