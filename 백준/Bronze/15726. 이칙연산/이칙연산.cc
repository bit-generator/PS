#include <iostream>
using namespace std;

int A, B, C;
int ans1, ans2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B >> C;
    ans1 = (long double)A * B / C;
    ans2 = (long double)A / B * C;
    if(ans1 > ans2) cout << ans1;
    else cout << ans2;
    return 0;
}