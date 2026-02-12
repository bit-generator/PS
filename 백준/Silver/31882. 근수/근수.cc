#include <iostream>
#include <string>
using namespace std;

int N;
long long ans;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> S;
    int start = 0;
    while(start < N) {
        if(S[start] == '2') {
            int cnt = 0;
            while(start < N && S[start] == '2') {
                ++cnt;
                ++start;
            }
            
            for(int i = 1; i <= cnt; ++i) {
                ans += ((long long)i * (cnt - i + 1));
            }
        }
        
        ++start;
    }
    
    cout << ans;
    return 0;
}