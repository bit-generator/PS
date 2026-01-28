#include <iostream>
#include <unordered_set>
using namespace std;

int N, M, num, ans;
unordered_set<int> us;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        us.clear();
        ans = 0;
        
        while(N--) {
            cin >> num;
            us.insert(num);
        }
    
        while(M--) {
            cin >> num;
            if(us.find(num) != us.end()) ++ans;
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}