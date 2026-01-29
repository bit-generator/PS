#include <iostream>
using namespace std;

int a, b, bit;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 5; ++i) {
        cin >> bit;
        a |= (bit << i);
    }
    
    for(int i = 0; i < 5; ++i) {
        cin >> bit;
        b |= (bit << i);
    }
    
    if((a ^ b) == 0b11111) cout << 'Y';
    else cout << 'N';
    return 0;
}