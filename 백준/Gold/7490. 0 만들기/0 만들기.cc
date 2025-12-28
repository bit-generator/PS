#include <iostream>
using namespace std;

int T, N;
char sign[3] = {' ', '+', '-'};
char signlist[10];

void operation(int& sum, int operand, char opr) {
    switch(opr) {
        case '+':
            sum += operand;
            break;
        case '-':
            sum -= operand;
            break;
        default:
            break;
    }
}

void solve() {
    int sum = 0;
    int operand = 1;
    char opr = '+';
    
    for(int i = 2; i <= N; ++i) {
        char ch = signlist[i - 2];
        switch(ch) {
            case '+':
            case '-':
                operation(sum, operand, opr);
                opr = ch;
                operand = i;
                break;
            case ' ':
                operand = operand * 10 + i;
                break;
            default:
                break;
        }
    }
    
    operation(sum, operand, opr);
    if(sum == 0) {
        for(int i = 1; i < N; ++i) {
            cout << i << signlist[i - 1];
        }
        cout << N << '\n';
    }
}

void backtrack(int cnt) {
    if(cnt == N - 1) {
        solve();
        return;
    }
    
    for(int i = 0; i < 3; ++i) {
        signlist[cnt] = sign[i];
        backtrack(cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N;
        backtrack(0);
        cout << '\n';
    }
    
    return 0;
}