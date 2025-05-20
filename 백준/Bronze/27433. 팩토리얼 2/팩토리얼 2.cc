#include <iostream>
using namespace std;

int N;
long long ans = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) ans *= i;
    cout << ans;
    return 0;
}