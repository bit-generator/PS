#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, pos, cnt, ans, rcnt, bcnt;
string str;
char color;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> str;
    for(int i = 0; i < N; ++i) {
        if(str[i] == 'R') ++rcnt;
        else ++bcnt;
    }
    ans = min(rcnt, bcnt);
    
    color = str[pos];
    while(pos < N && str[pos] == color) ++pos;
    while(pos < N) {
        if(str[pos++] == color) ++cnt;
    }
    ans = min(ans, cnt);
    
    cnt = 0, pos = N - 1;
    color = str[pos];
    while(pos >= 0 && str[pos] == color) --pos;
    while(pos >= 0) {
        if(str[pos--] == color) ++cnt;
    }
    ans = min(ans, cnt);
    
    cout << ans;
    return 0;
}