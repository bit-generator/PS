#include <iostream>
#include <string>
using namespace std;

int T;
long long N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N;
        long long bin = 1;
        int cnt = 1;
        while(bin * 2 <= N) {
            bin <<= 1;
            ++cnt;
        }
        
        long long pos = N - bin;
        while(cnt) {
            string ans = to_string(cnt);
            string tmp = to_string(pos + 1);
            for(int i = 0; i < 18 - tmp.length(); ++i) ans += '0';
            ans += tmp;
            cout << ans << '\n';
            pos >>= 1;
            --cnt;
        }
    }
    
    return 0;
}