#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;
using pis = pair<int, string>;

struct comp {
    bool operator() (const pis& p1, const pis& p2) {
        return p1.second > p2.second;
    }
};

int p, l, m;
string n;
priority_queue<pis, vector<pis>, comp> pq[300];
int roomLv[300], len;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> p >> m;
    while(p--) {
        cin >> l >> n;
        for(int i = 0; i <= len; ++i) {
            if(pq[i].empty()) {
                roomLv[i] = l;
                ++len;
            }
            else {
                if(pq[i].size() == m) continue;
                if(l < roomLv[i] - 10 || roomLv[i] + 10 < l) continue;
            }
            
            pq[i].emplace(l, n);
            break;
        }
    }
    
    for(int i = 0; i < len; ++i) {
        if(pq[i].size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";
        
        while(!pq[i].empty()) {
            cout << pq[i].top().first << ' ' << pq[i].top().second << '\n';
            pq[i].pop();
        }
    }
    
    return 0;
}