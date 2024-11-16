#include <iostream>
using namespace std;

int X, L, R;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> X >> L >> R;
    if(X >= L && X <= R) {
        cout << X;
    }
    else if(X < L) {
        cout << L;
    }
    else if(X > R) {
        cout << R;
    }
    
    return 0;
}