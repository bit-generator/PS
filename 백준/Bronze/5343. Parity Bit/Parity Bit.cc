#include <iostream>
#include <string>
using namespace std;

int N;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> str;
        int ans = 0;
        
        for(int i = 0; i < str.length(); i += 8) {
            int cnt = 0;
            for(int j = 0; j < 8; ++j) {
                if(str[i + j] == '1') ++cnt;
            }
            
            if(cnt % 2) ++ans;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}