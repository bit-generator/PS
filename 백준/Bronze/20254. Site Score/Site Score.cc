#include <iostream>
using namespace std;

int UR, TR, UO, TO;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> UR >> TR >> UO >> TO;
    cout << 56 * UR + 24 * TR + 14 * UO + 6 * TO;
    return 0;
}