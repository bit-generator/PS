#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int R, C, reg_cnt, ans, bird1, bird2;
char board[1500][1500];
int region[1500][1500];
int melt[1500][1500];
int parent[1300000];
queue<pair<int, int>> meltpos, checkpos;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool validRange(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int find(int x) {
    if (parent[x] == x) return x;
    else return x = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.emplace(x, y);
    region[x][y] = ++reg_cnt;
    if (board[x][y] == 'L') {
        if (bird1 == 0) bird1 = reg_cnt;
        else bird2 = reg_cnt;
    }

    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if (!validRange(nx, ny)) continue;
            if (board[nx][ny] == 'X') {
                melt[nx][ny] = reg_cnt;
                meltpos.emplace(nx, ny);
                continue;
            }
            if (region[nx][ny] != 0) continue;

            if (board[nx][ny] == 'L') {
                if (bird1 == 0) bird1 = reg_cnt;
                else bird2 = reg_cnt;
            }

            region[nx][ny] = reg_cnt;
            q.emplace(nx, ny);
        }
    }
}

void meltIce() {
    while (!meltpos.empty()) {
        int x = meltpos.front().first;
        int y = meltpos.front().second;
        meltpos.pop();

        if (region[x][y] != 0) continue;
        board[x][y] = '.';
        region[x][y] = melt[x][y];
        melt[x][y] = 0;
        checkpos.emplace(x, y);
    }
}

void getNextMelt() {
    while (!checkpos.empty()) {
        int x = checkpos.front().first;
        int y = checkpos.front().second;
        checkpos.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!validRange(nx, ny)) continue;
            if (board[nx][ny] == 'X') {
                melt[nx][ny] = region[x][y];
                meltpos.emplace(nx, ny);
            }
            else {
                if (find(region[x][y]) == find(region[nx][ny])) continue;
                else {
                    Union(region[x][y], region[nx][ny]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 'X' || region[i][j] != 0) continue;
            bfs(i, j);
        }
    }

    for (int i = 1; i <= reg_cnt; i++) parent[i] = i;

    while (find(bird1) != find(bird2)) {
        meltIce();
        getNextMelt();
        ans++;
    }

    cout << ans;
    return 0;
}