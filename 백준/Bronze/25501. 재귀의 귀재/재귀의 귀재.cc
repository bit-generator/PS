#include <iostream>
#include <string>
using namespace std;

int T;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> str;
        int cnt = 0, len = str.length();
        bool isPalindrome = true;
        
        for(int i = 0; i <= len / 2; ++i) {
            ++cnt;
            if(str[i] != str[len - i - 1]) {
                isPalindrome = false;
                break;
            }
        }
        
        cout << isPalindrome << ' ' << cnt << '\n';
    }
    
    return 0;
}