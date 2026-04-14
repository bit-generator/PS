#include <iostream>
using namespace std;

long long N, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> b;
    long long pow = (1LL << (b + 1)) - 1;
    if(N <= pow) cout << "yes";
    else cout << "no";
    return 0;
}