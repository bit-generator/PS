#include <iostream>
#include <utility>
#include <algorithm>
#define X    first
#define Y    second
using namespace std;
using pii = pair<int, int>;

int N, ans, maxCnt;
pii lines[3001][2];
int parent[3001];
int urank[3001];
int cnt[3001];

pii operator-(const pii& a, const pii& b) {
    return {b.X - a.X, b.Y - a.Y};
}

int CCW(const pii& p1, const pii& p2, const pii& p3) {
    pii V1 = p2 - p1;
    pii V2 = p3 - p1;
    int cross = V1.X * V2.Y - V1.Y * V2.X;
    if(cross > 0) return 1;
    else if(cross == 0) return 0;
    else return -1;
}

bool isCrossed(int id1, int id2) {
    pii& p1 = lines[id1][0], &p2 = lines[id1][1];
    pii& p3 = lines[id2][0], &p4 = lines[id2][1];
    int ccw[4] = {CCW(p1, p2, p3), CCW(p1, p2, p4), CCW(p3, p4, p1), CCW(p3, p4, p2)};
    if(ccw[0] * ccw[1] == 1 || ccw[2] * ccw[3] == 1) return false;
    else {
        if(ccw[0] == 0 && ccw[1] == 0) {
            if((p1 < p4 && p2 < p3) || (p3 < p2 && p4 < p1)) return false;
        }
    }
    
    return true;
}

int find(int x) {
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(urank[a] == urank[b]) ++urank[a];
    if(urank[a] > urank[b]) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> lines[i][0].X >> lines[i][0].Y >> lines[i][1].X >> lines[i][1].Y;
        if(lines[i][0] > lines[i][1]) swap(lines[i][0], lines[i][1]);
    }
    
    for(int i = 1; i <= N; ++i) parent[i] = i;
    
    for(int i = 1; i <= N - 1; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            if(find(i) == find(j)) continue;
            if(isCrossed(i, j)) {
                Union(i, j);
            }
        }
    }
    
    for(int i = 1; i <= N; ++i) ++cnt[find(i)];
    for(int i = 1; i <= N; ++i) {
        if(cnt[i]) {
            ++ans;
            maxCnt = max(maxCnt, cnt[i]);
        }
    }
    
    cout << ans << '\n' << maxCnt;
    return 0;
}