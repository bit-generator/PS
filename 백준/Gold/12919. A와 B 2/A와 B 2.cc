#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str1, str2;
bool ans;

void solve(int st, int en) {
    if(st < en) {
        if(en - st + 1 == str1.length()) {
            string tmp = str2.substr(st, en - st + 1);
            if(str1 == tmp) {
                ans = true;
            }
        }
        else {
            if(str2[en] == 'A') {
                solve(st, en - 1);
                if(ans) return;
            }
            
            if(str2[st] == 'B') {
                solve(en, st + 1);
            }
        }
    }
    else {
        if(st - en + 1 == str1.length()) {
            string tmp = str2.substr(en, st - en + 1);
            reverse(tmp.begin(), tmp.end());
            if(str1 == tmp) {
                ans = true;
            }
        }
        else {
            if(str2[en] == 'A') {
                solve(st, en + 1);
                if(ans) return;
            }
            
            if(str2[st] == 'B') {
                solve(en, st - 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str1 >> str2;
    
    int st = 0, en = str2.length() - 1;
    solve(st, en);
    
    cout << (int)ans;
    return 0;
}