#include <iostream>
#include <string>
using namespace std;

int T, m, n, k, num;
string str[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        cin >> m;
        for(int i = 0; i < m; ++i) cin >> str[i];
        cout << "Scenario #" << tc << ":\n";
        cin >> n;
        while(n--) {
            cin >> k;
            string ans = "";
            while(k--) {
                cin >> num;
                ans += str[num];
            }
            
            cout << ans << '\n';
        }
        
        cout << '\n';
    }
    
    return 0;
}