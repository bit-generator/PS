#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int N;
pair<int, int> arr[10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i].first >> arr[i].second;
    arr[N] = arr[0];
    
    long long sum1 = 0, sum2 = 0;
    for(int i = N; i > 0; --i) {
        sum1 += ((long long)arr[i].first * arr[i - 1].second);
        sum2 += ((long long)arr[i].second * arr[i - 1].first);
    }
    
    double ans = (double)abs(sum1 - sum2) / 2;
    cout.precision(1);
    cout << fixed << ans;
    return 0;
}