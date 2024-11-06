#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, E;
long long ans;
vector<tuple<int, int, int>> v;
int parent[1001];

int find(int x) {
    if(x == parent[x]) return x;
    else return x = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> E;
            if(i < j) {
                v.emplace_back(E, i, j);
            }
        }
    }
    
    sort(v.begin(), v.end());
    for(int i = 1; i <= N; i++) parent[i] = i;
    int cnt = 0;
    
    for(auto tp : v) {
        int a, b, cost;
        tie(cost, a, b) = tp;
        if(find(a) == find(b)) continue;
        
        Union(a, b);
        ans += cost;
        if(++cnt == N - 1) {
            break;
        }
    }
    
    cout << ans;
    return 0;
}