#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, T, ans;
int board[40][40];

void filter(int row, int col) {
    vector<int> v;
    for(int i = row; i < row + 3; ++i) {
        for(int j = col; j < col + 3; ++j) {
            v.push_back(board[i][j]);
        }
    }
    sort(v.begin(), v.end());
    if(v[4] >= T) ++ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> R >> C;
    for(int i = 0; i < R; ++i) {
        for(int j = 0; j < C; ++j) {
            cin >> board[i][j];
        }
    }
    cin >> T;
    
    for(int i = 0; i <= R - 3; ++i) {
        for(int j = 0; j <= C - 3; ++j) {
            filter(i, j);
        }
    }
    
    cout << ans;
    return 0;
}