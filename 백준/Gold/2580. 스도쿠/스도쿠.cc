#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int board[9][9];
bool h[9][10], v[9][10], sq[9][10];
vector<pair<int, int>> blank;
bool solved;

void backtrack(int idx) {
    if(idx == blank.size()) {
        solved = true;
        return;
    }
    
    int r = blank[idx].first, c = blank[idx].second;
    int sqidx = r / 3 * 3 + c / 3;
    for(int i = 1; i <= 9; ++i) {
        if(h[r][i] || v[c][i] || sq[sqidx][i]) continue;
        h[r][i] = true; v[c][i] = true;
        sq[sqidx][i] = true;
        board[r][c] = i;
        backtrack(idx + 1);
        h[r][i] = false; v[c][i] = false;
        sq[sqidx][i] = false;
        
        if(solved) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> board[i][j];
            if(board[i][j] == 0) {
                blank.emplace_back(i, j);
            }
            else {
                h[i][board[i][j]] = true;
                v[j][board[i][j]] = true;
                sq[i / 3 * 3 + j / 3][board[i][j]] = true;
            }
        }
    }
    
    backtrack(0);
    
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}