#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;

int N, M, T, U, V;
bool peopleflag[51], partyflag[51];
vector<int> people[51], party[51];
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        peopleflag[cur] = true;
        
        for(int i : people[cur]) {
            if(partyflag[i]) continue;
            partyflag[i] = true;
            
            for(int nxt : party[i]) {
                if(peopleflag[nxt]) continue;
                q.push(nxt);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> T;
    for(int i = 0; i < T; i++) {
        cin >> U;
        q.push(U);
    }
    
    for(int i = 1; i <= M; i++) {
        cin >> U;
        while(U--) {
            cin >> V;
            people[V].push_back(i);
            party[i].push_back(V);
        }
    }
    
    bfs();
    cout << M - accumulate(partyflag, partyflag + M + 1, 0);
    return 0;
}