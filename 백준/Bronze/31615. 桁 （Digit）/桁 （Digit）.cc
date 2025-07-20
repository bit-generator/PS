#include <iostream>
using namespace std;

int A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B;
    int ans = A + B;
    if(ans < 10) cout << 1;
    else if(ans < 100) cout << 2;
    else cout << 3;
    
    return 0;
}