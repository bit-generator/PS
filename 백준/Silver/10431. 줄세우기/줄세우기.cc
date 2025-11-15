#include <iostream>
#include <set>
using namespace std;

int P, T, N, ans;
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> P;
    while(P--) {
        cin >> T;
        ans = 0;
        s.clear();
        
        for(int i = 0; i < 20; ++i) {
            cin >> N;
            s.insert(N);
            int dist = distance(s.find(N), s.end()) - 1;
            ans += dist;
        }
        
        cout << T << ' ' << ans << '\n';
    }
    
    return 0;
}