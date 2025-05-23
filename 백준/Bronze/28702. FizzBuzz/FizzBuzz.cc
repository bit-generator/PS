#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string s[3];
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) cin >> s[i];
    for(int i = 0; i < 3; ++i) {
        if(isdigit(s[i][0])) {
            ans = stoi(s[i]) + 3 - i;
            break;
        }
    }
    
    if(ans % 3 == 0 && ans % 5 == 0) cout << "FizzBuzz";
    else if(ans % 3 == 0) cout << "Fizz";
    else if(ans % 5 == 0) cout << "Buzz";
    else cout << ans;
    return 0;
}