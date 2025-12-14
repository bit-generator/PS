#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str;
int len, cnt, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    len = count(str.begin(), str.end(), 'b');
    int start = 0, last = 0;
    while(last < len) {
        if(str[last++] == 'a') ++cnt;
    }
    ans = cnt;
    
    while(start < str.length()) {
        if(str[last++] == 'a') ++cnt;
        if(str[start++] == 'a') --cnt;
        ans = min(ans, cnt);
        if(last == str.length()) last = 0;
    }
    
    cout << ans;
    return 0;
}