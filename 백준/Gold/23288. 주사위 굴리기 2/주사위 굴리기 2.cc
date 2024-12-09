#include <iostream>
#include <deque>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int N, M, K, ans;
int board[20][20];
deque<int> dice = {2, 1, 5, 6};
int diceX = 0, diceY = 0;
int diceL = 4, diceR = 3;
int dir = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
bool visit[20][20];

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

void roll() {
    if(!validRange(diceX + dx[dir], diceY + dy[dir])) {
        dir = (dir + 2) % 4;
    }
    diceX += dx[dir];
    diceY += dy[dir];
    
    if(dir == 0) {
        swap(dice[1], diceR);
        swap(diceL, dice[3]);
        swap(dice[1], dice[3]);
    }
    else if(dir == 1) {
        dice.push_front(dice.back());
        dice.pop_back();
    }
    else if(dir == 2) {
        swap(diceL, dice[1]);
        swap(dice[3], diceR);
        swap(dice[1], dice[3]);
    }
    else {
        dice.push_back(dice.front());
        dice.pop_front();
    }
}

void getScore() {
    queue<pair<int, int>> q;
    memset(visit, 0, sizeof(visit));
    q.emplace(diceX, diceY);
    visit[diceX][diceY] = true;
    int cnt = 1;
    
    while(!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; ++i) {
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(!validRange(nx, ny)) continue;
            if(board[nx][ny] != board[diceX][diceY] || visit[nx][ny]) continue;
            
            q.emplace(nx, ny);
            visit[nx][ny] = true;
            ++cnt;
        }
    }
    
    ans += (board[diceX][diceY] * cnt);
}

void changeDir() {
    if(dice[3] > board[diceX][diceY]) {
        dir = (dir + 1) % 4;
    }
    else if(dice[3] < board[diceX][diceY]) {
        dir = (dir + 3) % 4;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> K;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    
    while(K--) {
        roll();
        getScore();
        changeDir();
    }
    
    cout << ans;
    return 0;
}