#include <iostream>
using namespace std;

int S, F;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> S >> F;
    if(S > F) cout << "flight";
    else cout << "high speed rail";
    
    return 0;
}