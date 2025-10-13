#include <iostream>
#include <cstring>
using namespace std;

int T, n, m, a, b;
bool isImpossible;
int member[500];
int idx[501];
int indegree[501];
int sorted[500];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        memset(sorted, 0, sizeof(sorted));
        isImpossible = false;
        
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> member[i];
            idx[member[i]] = i;
            indegree[member[i]] = i;
        }
        
        cin >> m;
        while(m--) {
            cin >> a >> b;
            if(idx[a] < idx[b]) {
                ++indegree[a];
                --indegree[b];
            }
            else {
                --indegree[a];
                ++indegree[b];
            }
        }
        
        for(int i = 1; i <= n; ++i) {
            if(sorted[indegree[i]]) {
                isImpossible = true;
                break;
            }
            
            sorted[indegree[i]] = i;
        }
        
        if(isImpossible) cout << "IMPOSSIBLE\n";
        else {
            for(int i = 0; i < n; ++i) {
                cout << sorted[i] << ' ';
            }
            cout << '\n';
        }
    }
    
    return 0;
}