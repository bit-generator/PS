#include <iostream>
using namespace std;

int L, T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> L >> T;
    cout << T * 2 - L;
    return 0;
}