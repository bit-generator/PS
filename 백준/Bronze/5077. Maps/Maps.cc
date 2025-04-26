#include <iostream>
using namespace std;

int T, Li, Ci, Lm, Cm, ans;
char piece[12][12];
char board[35][35];

bool isMatch(int x, int y) {
    for(int i = 0; i < Li; ++i) {
        for(int j = 0; j < Ci; ++j) {
            if(piece[i][j] != board[x + i][y + j]) return false;
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> Li >> Ci;
        for(int i = 0; i < Li; ++i) {
            for(int j = 0; j < Ci; ++j) {
                cin >> piece[i][j];
            }
        }
        
        cin >> Lm >> Cm;
        for(int i = 0; i < Lm; ++i) {
            for(int j = 0; j < Cm; ++j) {
                cin >> board[i][j];
            }
        }
        
        ans = 0;
        for(int i = 0; i < Lm - Li + 1; ++i) {
            for(int j = 0; j < Cm - Ci + 1; ++j) {
                if(isMatch(i, j)) ++ans;
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}