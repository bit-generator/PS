#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M, cheeseCnt, ans;
queue<pair<int, int>> startPos, meltPos;
int board[100][100];
bool visit[100][100];
int meltCnt[100][100];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    visit[x][y] = true;

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (!validRange(nx, ny) || visit[nx][ny]) continue;
            if (board[nx][ny] == 1) {
                if(++meltCnt[nx][ny] == 2) meltPos.emplace(nx, ny);
                continue;
            }

            q.emplace(nx, ny);
            visit[nx][ny] = true;
        }
    }
}

void applyMelting() {
    while (!meltPos.empty()) {
        int x = meltPos.front().first;
        int y = meltPos.front().second;
        meltPos.pop();

        board[x][y] = 0;
        startPos.emplace(x, y);
        cheeseCnt--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) cheeseCnt++;
        }
    }

    startPos.emplace(0, 0);
    while (cheeseCnt > 0) {
        while (!startPos.empty()) {
            int x = startPos.front().first;
            int y = startPos.front().second;
            startPos.pop();

            if (visit[x][y]) continue;
            bfs(x, y);
        }

        applyMelting();
        ans++;
    }

    cout << ans;
    return 0;
}