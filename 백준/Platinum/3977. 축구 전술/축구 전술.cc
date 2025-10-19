#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, M, A, B, idCnt, head;
int rel[100000][2];
vector<int> graph[100000];
vector<int> st;
int id[100000], parent[100000], fin[100000], indegree[100000];
bool isExist;

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
            if(cur == tmp) break;
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
        for(int i = 0; i < N; ++i) graph[i].clear();
        st.clear();
        memset(id, 0, sizeof(id));
        memset(fin, 0, sizeof(id));
        memset(indegree, 0, sizeof(indegree));
        idCnt = 0; head = -1;
        isExist = false;
        
        for(int i = 0; i < M; ++i) {
            cin >> rel[i][0] >> rel[i][1];
            graph[rel[i][0]].push_back(rel[i][1]);
        }
        
        for(int i = 0; i < N; ++i) {
            if(fin[i]) continue;
            dfs(i);
        }
        
        for(int i = 0; i < M; ++i) {
            int a = parent[rel[i][0]];
            int b = parent[rel[i][1]];
            if(a == b) continue;
            ++indegree[b];
        }
        
        for(int i = 0; i < N; ++i) {
            if(!indegree[parent[i]]) {
                if(head == -1) head = parent[i];
                else if(head != parent[i]) {
                    head = -1;
                    break;
                }
                
                st.push_back(i);
            }
        }
        
        if(head == -1) cout << "Confused\n";
        else {
            for(int i : st) cout << i << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}