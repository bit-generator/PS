#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

int R, C, ans, X, Y;
pair<int, int> M;
char board[25][25];
bool check[25][25];
queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
unordered_map<int, char> outs = {
    {0b0101, '|'}, {0b1010, '-'}, {0b1111, '+'},
    {0b0011, '1'}, {0b0110, '2'}, {0b1100, '3'}, {0b1001, '4'}
};
unordered_map<char, int> outof = {
    {'|', 0b0101}, {'-', 0b1010}, {'+', 0b1111},
    {'1', 0b0011}, {'2', 0b0110}, {'3', 0b1100}, {'4', 0b1001}
};

bool validRange(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

void bfs() {
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            if(!(outof[board[curx][cury]] & (1 << i))) continue;
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || check[nx][ny]) continue;
            if(board[nx][ny] == '.') {
                X = nx; Y = ny;
                return;
            }
            
            q.emplace(nx, ny);
            check[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 'M') M = {i, j};
        }
    }
    
    for(int i = 0; i < 4; ++i) {
        int nx = M.first + dx[i];
        int ny = M.second + dy[i];
        if(!validRange(nx, ny)) continue;
        if(board[nx][ny] != '.') {
            q.emplace(nx, ny);
            check[nx][ny] = true;
            break;
        }
    }
    
    bfs();
    for(int i = 0; i < 4; ++i) {
        int nx = X + dx[i];
        int ny = Y + dy[i];
        if(!validRange(nx, ny) || board[nx][ny] == '.') continue;
        if(outof[board[nx][ny]] & (1 << ((i + 2) % 4))) {
            ans |= (1 << i);
        }
    }
    cout << X + 1 << ' ' << Y + 1 << ' ' << outs[ans];
    return 0;
}