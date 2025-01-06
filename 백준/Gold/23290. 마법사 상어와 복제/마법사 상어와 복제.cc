#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int M, S, fx, fy, d, ans;
vector<int> board[5][5], copied[5][5], moved[5][5];
int smell[5][5];
int check[5][5];
pair<int, int> shark;
int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int sharkPath[3], determined[3];
int maxFish;

bool validRange(int x, int y) {
    return x >= 1 && x <= 4 && y >= 1 && y <= 4;
}

void copyMagic() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
			copied[i][j] = board[i][j];
        }
    }

    ans <<= 1;
}

bool determineDir(int x, int y, int& dir) {
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (!validRange(nx, ny) || smell[nx][ny] || shark == make_pair(nx, ny)) {
            dir = (dir + 6) % 8 + 1;
            continue;
        }

        return true;
    }

    return false;
}

void moveFish() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            moved[i][j].clear();
        }
    }

    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int dir : copied[i][j]) {
                if (determineDir(i, j, dir)) {
                    moved[i + dx[dir]][j + dy[dir]].push_back(dir);
                }
                else {
                    moved[i][j].push_back(dir);
                }
            }
        }
    }
}

void getPath(int x, int y, int cnt, int fishCnt) {
    if (cnt == 3) {
        if (fishCnt > maxFish) {
            memcpy(determined, sharkPath, sizeof(int) * 3);
            maxFish = fishCnt;
        }
        return;
    }

    int i = 3;
    for (int lp = 0; lp < 4; ++lp, i = (i + 6) % 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!validRange(nx, ny)) continue;
        sharkPath[cnt] = i;
        if (!(check[nx][ny]++)) fishCnt += moved[nx][ny].size();
        getPath(nx, ny, cnt + 1, fishCnt);
        if (!(--check[nx][ny])) fishCnt -= moved[nx][ny].size();
    }
}

void moveShark() {
    maxFish = -1;
    getPath(shark.first, shark.second, 0, 0);
    for (int i = 0; i < 3; ++i) {
        shark.first += dx[determined[i]];
        shark.second += dy[determined[i]];
        if (!moved[shark.first][shark.second].empty()) {
            ans -= moved[shark.first][shark.second].size();
            moved[shark.first][shark.second].clear();
            smell[shark.first][shark.second] = 3;
        }
    }
}

void removeSmell() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (smell[i][j] > 0) --smell[i][j];
        }
    }
}

void completeMagic() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            board[i][j].insert(board[i][j].end(), moved[i][j].begin(), moved[i][j].end());
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> S;
    for (int i = 0; i < M; ++i) {
        cin >> fx >> fy >> d;
        board[fx][fy].push_back(d);
    }
    cin >> shark.first >> shark.second;

    ans = M;

    while (S--) {
        copyMagic();
        moveFish();
        moveShark();
        removeSmell();
        completeMagic();
    }

    cout << ans;
    return 0;
}