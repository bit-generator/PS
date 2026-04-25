#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int T, A, B;
string visit[10000];
char cmd[4] = {'D', 'S', 'L', 'R'};

int getNext(int num, char c) {
    switch(c) {
        case 'D':
            return (num * 2) % 10000;
            break;
        case 'S':
            return (num + 9999) % 10000;
            break;
        case 'L':
            return (num / 1000) + (num % 1000) * 10;
            break;
        case 'R':
            return (num % 10) * 1000 + (num / 10);
            break;
    }
    
    return -1;
}

void bfs() {
    queue<int> q;
    q.push(A);
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nxt = getNext(cur, cmd[i]);
            if(!visit[nxt].empty() || nxt == cur || nxt == A) continue;
            
            visit[nxt] = visit[cur] + cmd[i];
            if(nxt == B) return;
            q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> A >> B;
        fill(visit, visit + 10000, "");
        bfs();
        cout << visit[B] << '\n';
    }
    
    return 0;
}