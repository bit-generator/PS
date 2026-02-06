#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int T, N, ans;
string signal, media;
unordered_set<char> us;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        cin >> N >> signal;
        ans = 0;
        us.clear();
        
        for(char c : signal) us.insert(c);
        
        while(N--) {
            cin >> media;
            for(char c : us) {
                if(media.find(c) != -1) {
                    ++ans;
                    break;
                }
            }
        }
        
        cout << "Data Set " << tc << ":\n" << ans << "\n\n";
    }
    
    return 0;
}