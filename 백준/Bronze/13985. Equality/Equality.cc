#include <iostream>
using namespace std;

int a, b, c;
char ch1, ch2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> ch1 >> b >> ch2 >> c;
    if(a + b == c) cout << "YES";
    else cout << "NO";
    return 0;
}