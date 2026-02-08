#include <iostream>
#include <string>
using namespace std;

string s, t;
int target;
bool ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> s >> t) {
        target = 0;
        ans = false;
        
        for(int i = 0; i < t.length(); ++i) {
            if(t[i] == s[target]) {
                if(++target >= s.length()) {
                    ans = true;
                    break;
                }
            }
        }
        
        if(ans) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}