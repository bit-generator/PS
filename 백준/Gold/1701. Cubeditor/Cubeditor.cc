#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

string str;
int F[5000];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    
    for(int n = 0; n < str.length(); ++n) {
        memset(F, 0, sizeof(F));
        int j = n;
        
        for(int i = n + 1; i < str.length(); ++i) {
            while(j > n && str[i] != str[j]) j = F[j - 1] + n;
            if(str[i] == str[j]) F[i] = ++j - n;
            ans = max(ans, F[i]);
        }
    }
    
    
    cout << ans;
    return 0;
}