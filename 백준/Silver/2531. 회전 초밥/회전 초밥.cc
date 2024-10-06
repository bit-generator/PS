#include <iostream>
#include <algorithm>
using namespace std;

int N, d, k, c, ans;
int sushi[3001];
int belt[30000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++) cin >> belt[i];
    sushi[c] = 1;
    
    int start = 0, last = 0;
    int cnt = 1;
    while(last < k) {
        if(sushi[belt[last++]]++ == 0) cnt++;
    }
    ans = cnt;
    
    while(start < N) {
        if(--sushi[belt[start++]] == 0) cnt--;
        if(sushi[belt[last++]]++ == 0) cnt++;
        ans = max(ans, cnt);
        
        if(last == N) last = 0;
    }

    cout << ans;
    return 0;
}