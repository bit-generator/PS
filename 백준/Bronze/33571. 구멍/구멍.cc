#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int upper[26], lower[26], ans;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    upper[0] = 1; upper[1] = 2; upper[3] = 1; upper[14] = 1;
    upper[15] = 1; upper[16] = 1; upper[17] = 1;
    lower[0] = 1; lower[1] = 1; lower[3] = 1; lower[4] = 1;
    lower[6] = 1; lower[14] = 1; lower[15] = 1; lower[16] = 1;
    
    getline(cin, str);
    for(char c : str) {
        if(islower(c)) {
            ans += lower[c - 'a'];
        }
        else if(isupper(c)) {
            ans += upper[c - 'A'];
        }
        else if(c == '@') ++ans;
    }
    
    cout << ans;
    return 0;
}