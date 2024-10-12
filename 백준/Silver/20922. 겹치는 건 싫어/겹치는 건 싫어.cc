#include <iostream>
using namespace std;

int N, K, ans;
int A[200000];
int cnt[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> A[i];
    
    int start = 0, last = 0;
    while(last < N) {
        cnt[A[last]]++;
        while(cnt[A[last]] > K) cnt[A[start++]]--;
        ans = ans < (last - start + 1) ? (last - start + 1) : ans;
        last++;
    }
    
    cout << ans;
    return 0;
}