#include <iostream>
#include <algorithm>
using namespace std;

int A, B, C, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B >> C >> D;
    
    cout << min(B + C, A + D);
    return 0;
}