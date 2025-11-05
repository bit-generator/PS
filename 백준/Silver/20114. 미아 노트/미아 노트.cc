#include <iostream>
#include <string>
using namespace std;

int N, H, W;
char board[10][1000];
char ans[101];

void decrypt(int idx) {
    for(int i = 0; i < H; ++i) {
        for(int j = idx * W; j < (idx + 1) * W; ++j) {
            if(board[i][j] != '?') {
                ans[idx] = board[i][j];
                return;
            }
        }
    }
    
    ans[idx] = '?';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> H >> W;
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < N * W; ++j) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        decrypt(i);
    }
    
    cout << ans;
    return 0;
}