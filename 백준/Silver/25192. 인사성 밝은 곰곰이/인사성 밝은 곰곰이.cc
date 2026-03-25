#include <iostream>
#include <string>
#include <set>
using namespace std;

int N, ans;
string str;
set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> str;
        if(str == "ENTER") {
            ans += s.size();
            s.clear();
        }
        else {
            s.insert(str);
        }
    }
    
    ans += s.size();
    cout << ans;
    return 0;
}