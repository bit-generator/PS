#include <iostream>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    cout << fixed;
    cout.precision(2);
    cout << (double)n / 4;
    
    return 0;
}