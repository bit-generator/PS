#include <iostream>
using namespace std;

int N, M;
char board[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = M - 1; j >= 0; --j) {
            cin >> board[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}