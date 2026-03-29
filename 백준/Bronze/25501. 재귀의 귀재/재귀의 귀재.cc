#include <iostream>
#include <string>
using namespace std;

int T, cnt;
string str;

int recursion(const string& s, int l, int r) {
    ++cnt;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const string& s){
    return recursion(s, 0, s.length() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> str;
        cnt = 0;
        cout << isPalindrome(str) << ' ' << cnt << '\n';
    }
    
    return 0;
}