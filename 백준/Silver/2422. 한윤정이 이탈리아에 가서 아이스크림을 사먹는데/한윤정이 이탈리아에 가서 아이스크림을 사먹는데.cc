#include <iostream>
using namespace std;

int N, M, a, b, ans;
int check[201][201];
int combi[4];

void backtrack(int cnt) {
    if(cnt > 3) {
        ++ans;
        return;
    }
    
    for(int i = combi[cnt - 1] + 1; i <= N; ++i) {
        bool mix = true;
        combi[cnt] = i;
        for(int j = 1; j < cnt; ++j) {
            if(check[combi[j]][combi[cnt]]) {
                mix = false;
                break;
            }
        }
        
        if(!mix) continue;
        backtrack(cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(M--) {
        cin >> a >> b;
        check[a][b] = true;
        check[b][a] = true;
    }
    
    backtrack(1);
    cout << ans;
    return 0;
}