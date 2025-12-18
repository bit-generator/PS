#include <iostream>
using namespace std;

int a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b;
    if(a * 2 >= b) cout << 'E';
    else cout << 'H';
    return 0;
}