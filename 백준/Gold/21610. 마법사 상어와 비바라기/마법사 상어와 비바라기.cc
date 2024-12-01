#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M, d, s, ans;
int board[51][51];
int cloud[51][51];
vector<pair<int, int>> moved;
int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

void move(int x, int y) {
    for(int i = 0; i < s; ++i) {
        x += dx[d];
        if(x < 1) x = N;
        else if(x > N) x = 1;
        y += dy[d];
        if(y < 1) y = N;
        else if(y > N) y = 1;
    }
    
    moved.emplace_back(x, y);
    ++board[x][y];
}

void moveClouds() {
    moved.clear();
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(cloud[i][j] == 1) {
                cloud[i][j] = 0;
                move(i, j);
            }
        }
    }
}

void copyWater() {
    for(auto p : moved) {
        for(int i = 1; i <= 4; ++i) {
            int nx = p.first + dx[i * 2];
            int ny = p.second + dy[i * 2];
            if(nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if(board[nx][ny] == 0) continue;
            ++board[p.first][p.second];
        }
        
        cloud[p.first][p.second] = -1;
    }
}

void generateClouds() {
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(cloud[i][j] == -1) {
                cloud[i][j] = 0;
                continue;
            }
            
            if(board[i][j] >= 2) {
                cloud[i][j] = 1;
                board[i][j] -= 2;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> board[i][j];
        }
    }
    
    cloud[N][1] = 1; cloud[N][2] = 1;
    cloud[N - 1][1] = 1; cloud[N - 1][2] = 1;
    
    while(M--) {
        cin >> d >> s;
        moveClouds();
        copyWater();
        generateClouds();
    }
    
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            ans += board[i][j];
        }
    }
    
    cout << ans;
    return 0;
}