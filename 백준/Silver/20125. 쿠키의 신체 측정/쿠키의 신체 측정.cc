#include <iostream>
using namespace std;

int N, hX, hY;
char board[1001][1001];
int dx[] = {0, 0, 1};
int dy[] = {-1, 1, 0};
int ans[5];

bool validRange(int x, int y) {
    return x >= 1 && x <= N && y >= 1 && y <= N;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> board[i][j];
            if(board[i][j] == '*' && board[i - 1][j] == '*' && board[i][j - 1] == '*') {
                hX = i, hY = j;
            }
        }
    }
    
    int curx = hX, cury = hY;
    for(int i = 0; i < 2; ++i) {
        int nx = curx + dx[i];
        int ny = cury + dy[i];
        while(validRange(nx, ny) && board[nx][ny] == '*') {
            ++ans[i];
            nx += dx[i];
            ny += dy[i];
        }
    }
    
    int nx = curx + dx[2];
    int ny = cury + dy[2];
    while(board[nx][ny] == '*') {
        ++ans[2];
        nx += dx[2];
        ny += dy[2];
    }
    
    for(int i = 0; i < 2; ++i) {
        int nnx = nx + dx[i];
        int nny = ny + dy[i];
        while(validRange(nnx, nny) && board[nnx][nny] == '*') {
            ++ans[3 + i];
            nnx += dx[2];
            nny += dy[2];
        }
    }
    
    cout << hX << ' ' << hY << '\n';
    for(int n : ans) cout << n << ' ';
    return 0;
}