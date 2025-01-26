#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;
using PQ = priority_queue<string, vector<string>, greater<>>;

int N, M;
string str, X, Y;
unordered_map<string, int> strMap;
unordered_map<int, string> idxMap;
vector<int> graph[1001];
queue<int> q;
PQ pq;
map<string, PQ> childs;
int indegree[1001];
int parent[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> str;
        strMap[str] = i;
        idxMap[i] = str;
        childs[str] = PQ();
    }

    cin >> M;
    while (M--) {
        cin >> X >> Y;
        graph[strMap[Y]].push_back(strMap[X]);
        ++indegree[strMap[X]];
    }

    for (int i = 1; i <= N; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
            pq.push(idxMap[i]);
        }
    }

    int sz = q.size();
    cout << sz << '\n';
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        for (int i : graph[idx]) {
            if (--indegree[i] == 0) q.push(i);
            parent[i] = idx;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if(parent[i] != 0) childs[idxMap[parent[i]]].push(idxMap[i]);
    }

    for (auto it = childs.begin(); it != childs.end(); ++it) {
        cout << it->first << ' ' << it->second.size() << ' ';
        while (!(it->second.empty())) {
            cout << it->second.top() << ' ';
            it->second.pop();
        }

        cout << '\n';
    }

    return 0;
}