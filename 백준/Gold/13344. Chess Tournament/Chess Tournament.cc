#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <utility>
using namespace std;

int N, M, K, L, cnt;
char ch;
vector<pair<int, int>> query;
vector<int> graph[50000];
queue<int> q;
unordered_set<int> united;
int indegree[50000];
int parent[50000];
int urank[50000];
bool inserted[50000];

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (urank[a] == urank[b]) ++urank[a];
    if (urank[a] > urank[b]) parent[b] = a;
    else parent[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; ++i) parent[i] = i;

    while (M--) {
        cin >> K >> ch >> L;
        if (ch == '>') {
            query.emplace_back(K, L);
        }
        else {
            Union(K, L);
        }
    }
    
    for(int i = 0; i < N; ++i) {
        united.insert(find(i));
    }

    for (const auto& p : query) {
        int k = find(p.first);
        int l = find(p.second);
        if (k == l) {
            cout << "inconsistent";
            return 0;
        }

        graph[k].push_back(l);
        ++indegree[l];
    }

    for (int i = 0; i < N; ++i) {
        if (indegree[find(i)] == 0 && !inserted[find(i)]) {
            q.push(find(i));
            inserted[find(i)] = true;
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : graph[cur]) {
            if (--indegree[find(nxt)] == 0) {
                q.push(find(nxt));
            }
        }

        ++cnt;
    }

    if (cnt != united.size()) cout << "inconsistent";
    else cout << "consistent";
    return 0;
}