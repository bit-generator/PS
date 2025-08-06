#include <iostream>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    if(N % 11 == 0) cout << 1;
    else cout << 0;
    return 0;
}