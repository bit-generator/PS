#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int N, M, K, ans = -1;
int check1[1'000'001], check2[1'000'001];

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(N, 0);

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt == K) break;

        for (int i = 0; i < M - 1; ++i) {
            for (int j = i + 1; j < M; ++j) {
                string tmp = to_string(cur);
                if (i == 0 && tmp[j] == '0') continue;
                swap(tmp[i], tmp[j]);
                int nxt = stoi(tmp);
                if (cnt % 2 && check1[nxt] == 0) {
                    q.emplace(nxt, cnt + 1);
                    check1[nxt] = cnt + 1;
                }
                else if (cnt % 2 == 0 && check2[nxt] == 0) {
                    q.emplace(nxt, cnt + 1);
                    check2[nxt] = cnt + 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    if(N == 1'000'000) {
        cout << 1000000;
        return 0;
    }
    
    M = to_string(N).length();
    bfs();

    int tens = [](int x) {
        int ret = 1;
        while (--x) ret *= 10;
        return ret;
        }(M);

    if (K % 2) {
        for (int i = tens * 10 - 1; i >= tens; --i) {
            if (check2[i] != 0) {
                ans = i;
                break;
            }
        }
    }
    else {
        for (int i = tens * 10 - 1; i >= tens; --i) {
            if (check1[i] != 0) {
                ans = i;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}