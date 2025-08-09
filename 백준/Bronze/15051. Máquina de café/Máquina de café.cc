#include <iostream>
using namespace std;

int A1, A2, A3, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A1 >> A2 >> A3;
    int sum1 = A1 * 4 + A2 * 2, sum2 = A1 * 2 + A3 * 2, sum3 = A2 * 2 + A3 * 4;
    ans = sum1 < sum2 ? sum1 : sum2;
    ans = ans < sum3 ? ans : sum3;
    cout << ans;
    return 0;
}