#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string s;
int F[1'000'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> s;
        if(s == ".") break;
        
        int j = 0;
        int sz = s.length();
        memset(F, 0, sizeof(F));
        
        for(int i = 1; i < sz; ++i) {
            while(j > 0 && s[i] != s[j]) j = F[j - 1];
            if(s[i] == s[j]) F[i] = ++j;
        }
        
        if(F[sz - 1] != 0 && F[sz - 1] % (sz - F[sz - 1]) == 0) {
            cout << F[sz - 1] / (sz - F[sz - 1]) + 1 << '\n';
        }
        else {
            cout << 1 << '\n';
        }
    }
    
    return 0;
}