#include <iostream>
#include <string>
using namespace std;

string S;
bool ans = true;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> S;
    for(int i = 0; i < S.length(); ) {
        string tmp = S.substr(i, 2);
        if(tmp == "pi" || tmp == "ka") {
            i += 2;
            continue;
        }
        
        if(S.substr(i, 3) == "chu") {
            i += 3;
            continue;
        }
        
        ans = false;
        break;
    }
    
    if(ans) cout << "YES";
    else cout << "NO";
    return 0;
}