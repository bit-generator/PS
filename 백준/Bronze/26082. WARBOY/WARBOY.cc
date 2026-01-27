#include <iostream>
using namespace std;

int A, B, C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B >> C;
    cout << B / A * C * 3;
    return 0;
}