#include <iostream>
using namespace std;

int N, M;
long long ans;
long long arr[1'000'001];
long long mods[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
        int mod = arr[i] % M;
        if(mod == 0) ++ans;
        ++mods[mod];
    }
    
    for(int i = 0; i < M; ++i) {
        long long cnt = (mods[i] * (mods[i] - 1)) / 2;
        ans += cnt;
    }
    
    cout << ans;
    return 0;
}