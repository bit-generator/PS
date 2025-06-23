#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int n, k;
int road[100001];
int visit[100001];
queue<int> q;

int operate(int x, int id) {
    switch(id) {
        case 0: x++; break;
        case 1: x--; break;
        case 2: x <<= 1; break;
    }
    
    return x;
}

int bfs() {
    q.push(n);
    visit[n] = 1;
    
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        if(cur == k) return visit[cur] - 1;
        
        for(int i = 0; i < 3; i++) {
            int next = operate(cur, i);
            if(next < 0 || next > 100000) continue;
            if(visit[next] != 0 && visit[next] <= visit[cur]) continue;
            road[next] = cur;
            visit[next] = visit[cur] + 1;
            q.push(next);
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;

    cout << bfs() << '\n';
    stack<int> st;
    int tmp = k;
    while(tmp != n) {
        st.push(tmp);
        tmp = road[tmp];
    }
    st.push(tmp);
    
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    return 0;
}