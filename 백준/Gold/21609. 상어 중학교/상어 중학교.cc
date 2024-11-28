#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

constexpr int EMPTY = -2;
constexpr int BLACK = -1;
constexpr int RAINBOW = 0;
int N, M, ans;
vector<vector<int>> board;
bool visit[20][20];
bool totalVisit[20][20];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<pair<int, int>> maxBlock;
vector<pair<int, int>> block;
int maxRainbowCnt;

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    memset(visit, 0, sizeof(visit));
    q.emplace(x, y);
    visit[x][y] = true;
    totalVisit[x][y] = true;
    block.emplace_back(x, y);
    int rainbowCnt = 0;
    int base = board[x][y];
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny) || visit[nx][ny]) continue;
            if(board[nx][ny] == base || board[nx][ny] == RAINBOW) {
                visit[nx][ny] = true;
                totalVisit[nx][ny] = true;
                if(board[nx][ny] == RAINBOW) ++rainbowCnt;
                q.emplace(nx, ny);
                block.emplace_back(nx, ny);
            }
        }
    }
    
    if(block.size() >= 2 && (maxBlock.size() < block.size()
      || (maxBlock.size() == block.size() && maxRainbowCnt <= rainbowCnt))) {
        maxBlock = block;
        maxRainbowCnt = rainbowCnt;
    }
}

void findMaxBlock() {
    maxBlock.clear();
    maxRainbowCnt = 0;
    memset(totalVisit, 0, sizeof(totalVisit));
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            if(board[i][j] == BLACK || board[i][j] == RAINBOW
               || board[i][j] == EMPTY || totalVisit[i][j]) continue;
            block.clear();
            bfs(i, j);
        }
    }
}

void deleteBlock() {
    ans += (maxBlock.size() * maxBlock.size());
    for(auto p : maxBlock) {
        board[p.first][p.second] = EMPTY;
    }
}

void applyGravity() {
    for(int j = 0; j < N; ++j) {
        int insertPos = N;
        while(true) {
            while(--insertPos > 0 && board[insertPos][j] != EMPTY);
            if(insertPos == 0) break;
            int targetPos = insertPos;
            while(--targetPos >= 0 && board[targetPos][j] == EMPTY);
            if(targetPos < 0) break;
            
            if(board[targetPos][j] == BLACK) {
                insertPos = targetPos;
                continue;
            }
            else {
                board[insertPos][j] = board[targetPos][j];
                board[targetPos][j] = EMPTY;
            }
        }
    }
}

void rotate(vector<vector<int>> prevBoard) {
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            board[i][j] = prevBoard[j][N - i - 1];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    board.resize(N, vector<int>(N, 0));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }
    
    while(true) {
        findMaxBlock();
        if(!maxBlock.size()) break;
        deleteBlock();
        applyGravity();
        rotate(board);
        applyGravity();
    }
    
    cout << ans;
    return 0;
}