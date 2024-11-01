#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

constexpr int ARCHER = -1;
int N, M, D, originCnt, enemyCnt, defeatCnt, ans;
int origin[15][15];
int board[16][15];
queue<pair<int, int>> q;

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void targetLock() {
    for (int k = 0; k < M; k++) {
        if (board[N][k] != ARCHER) continue;
        int targetX, targetY = 16;
        int minDist = 11;

        for (int i = N - D; i < N; i++) {
            for (int j = k - D; j <= k + D; j++) {
                if (!validRange(i, j) || !board[i][j]) continue;

                int dist = abs(i - N) + abs(j - k);
                if (dist > D) continue;

                if (dist < minDist || (dist == minDist && j < targetY)) {
                    minDist = dist;
                    targetX = i;
                    targetY = j;
                }
            }
        }

        if (targetY != 16) q.emplace(targetX, targetY);
    }
}

void attack() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (board[x][y]) {
            board[x][y] = 0;
            enemyCnt--;
            defeatCnt++;
        }
    }
}

void moveEnemy() {
    enemyCnt -= accumulate(board[N - 1], board[N - 1] + M, 0);
    for (int i = N - 1; i > 0; i--) {
        memcpy(board[i], board[i - 1], sizeof(int) * M);
    }
    memset(board[0], 0, sizeof(int) * M);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> origin[i][j];
            if (origin[i][j]) originCnt++;
        }
    }

    memset(board[N], ARCHER, sizeof(int) * 3);

    do {
        for (int i = 0; i < N; i++) {
            memcpy(board[i], origin[i], sizeof(int) * M);
        }
        enemyCnt = originCnt;
        defeatCnt = 0;

        while (enemyCnt) {
            targetLock();
            attack();
            moveEnemy();
        }

        ans = max(ans, defeatCnt);
    } while (next_permutation(board[N], board[N] + M));

    cout << ans;
    return 0;
}