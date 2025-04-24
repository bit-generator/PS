#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B >> C >> D;
    if(A > B) swap(A, B);
    if(C > D) swap(C, D);
    if(A > C) {
        swap(A, C);
        swap(B, D);
    }
    else if(A == C && B > D) swap(B, D);
    
    if(B < C) cout << (B - A + 1) + (D - C + 1);
    else if(B < D) cout << (B - A + 1) + (D - C + 1) - (B - C + 1);
    else cout << B - A + 1;
    
    return 0;
}