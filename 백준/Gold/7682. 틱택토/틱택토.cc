#include <iostream>
using namespace std;

string str;
char board[3][3];
int cntX, cntO;

bool isBingo(char ch) {
    bool bingo = false;
    
    for(int i = 0; i < 3; ++i) {
        int cntR = 0, cntC = 0;

        for(int j = 0; j < 3; ++j) {
            cntR += (board[i][j] == ch);
            cntC += (board[j][i] == ch);
        }

        if(cntR == 3 || cntC == 3) bingo = true;
    }
    
    int cntSlash = 0, cntBSlash = 0;
    for(int i = 0; i < 3; ++i) {
        cntBSlash += (board[i][i] == ch);
        cntSlash += (board[i][2 - i] == ch);
    }
    
    if(cntSlash == 3 || cntBSlash == 3) bingo = true;
    
    if(bingo) return true;
    else return false;
}

bool solve() {
    if(cntX == cntO) {
        if(isBingo('O') && !isBingo('X')) return true;
    }
    else if(cntX == cntO + 1) {
        if(cntX + cntO < 9) {
            if(isBingo('X') && !isBingo('O')) return true;
        }
        else {
            if(!isBingo('O')) return true;
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> str;
        if(str == "end") break;
        
        cntX = 0;
        cntO = 0;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                board[i][j] = str[i * 3 + j];
                if(board[i][j] == 'X') ++cntX;
                if(board[i][j] == 'O') ++cntO;
            }
        }
        
        if(solve()) cout << "valid\n";
        else cout << "invalid\n";
    }
    
    return 0;
}