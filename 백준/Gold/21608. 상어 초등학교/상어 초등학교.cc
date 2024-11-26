#include <iostream>
#include <utility>
using namespace std;

int N, ans;
int student[400];
bool favorite[401][401];
int board[20][20];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int score[5] = {0, 1, 10, 100, 1000};

bool validRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}

pair<int, int> getAroundInfo(int idx, int x, int y) {
    int favCnt = 0, emptyCnt = 0;
    for(int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!validRange(nx, ny)) continue;
        if(favorite[idx][board[nx][ny]]) ++favCnt;
        if(board[nx][ny] == 0) ++emptyCnt;
    }
    
    return {favCnt, emptyCnt};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N * N; ++i) {
        cin >> student[i];
        int tmp;
        for(int j = 0; j < 4; ++j) {
            cin >> tmp;
            favorite[student[i]][tmp] = true;
        }
    }
    
    for(int k = 0; k < N * N; ++k) {
        int maxFav = -1, maxEmpty = -1;
        int destX = 0, destY = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                if(board[i][j]) continue;
                pair<int, int> cnt = getAroundInfo(student[k], i, j);
                if(cnt.first > maxFav) {
                    destX = i;
                    destY = j;
                    maxFav = cnt.first;
                    maxEmpty = cnt.second;
                }
                else if(cnt.first == maxFav) {
                    if(cnt.second > maxEmpty) {
                        destX = i;
                        destY = j;
                        maxEmpty = cnt.second;
                    }
                }
            }
        }
        
        board[destX][destY] = student[k];
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            int cnt = getAroundInfo(board[i][j], i, j).first;
            ans += score[cnt];
        }
    }
    
    cout << ans;
    return 0;
}