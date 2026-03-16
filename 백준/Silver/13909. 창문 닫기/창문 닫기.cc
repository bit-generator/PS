#include <iostream>
using namespace std;

int N, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i * i <= N; ++i) ++ans;
    cout << ans;
    return 0;
}