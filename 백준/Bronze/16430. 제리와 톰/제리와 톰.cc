#include <iostream>
using namespace std;

int A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B;
    cout << B - A << ' ' << B;
    
    return 0;
}