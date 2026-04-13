#include <iostream>
using namespace std;

int N, M, ans;
char board[50][50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ) {
            while(j < M && board[i][j] != '-') ++j;
            if(j < M && board[i][j] == '-') {
                ++ans;
                while(j < M && board[i][j] == '-') ++j;
            }
        }
    }
    
    for(int j = 0; j < M; ++j) {
        for(int i = 0; i < N; ) {
            while(i < N && board[i][j] != '|') ++i;
            if(i < N && board[i][j] == '|') {
                ++ans;
                while(i < N && board[i][j] == '|') ++i;
            }
        }
    }
    
    cout << ans;
    return 0;
}