#include <iostream>
using namespace std;

int N, K, M;
int gold[1001], silver[1001], bronze[1001];
int ans = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    for(int i = 0; i < N; ++i) {
        cin >> M;
        cin >> gold[M] >> silver[M] >> bronze[M];
    }
    
    for(int i = 1; i <= N; ++i) {
        if(i == K) continue;
        if(gold[i] > gold[K]) ++ans;
        else if(gold[i] == gold[K]) {
            if(silver[i] > silver[K]) ++ans;
            else if(silver[i] == silver[K]) {
                if(bronze[i] > bronze[K]) ++ans;
            }
        }
    }
    
    cout << ans;
    return 0;
}