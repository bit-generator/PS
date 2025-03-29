#include <iostream>
using namespace std;

int N, ans;
int graph[21][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            cin >> graph[i][j];
        }
    }
    
    for(int i = 1; i <= N - 1; ++i) {
        for(int j = i + 1; j <= N; ++j) {
            ans += graph[i][j];
            
            for(int k = 1; k <= N; ++k) {
                if(i == k || j == k) continue;
                
                if(graph[i][j] == graph[i][k] + graph[k][j]) {
                    ans -= graph[i][j];
                    break;
                }
                else if(graph[i][j] > graph[i][k] + graph[k][j]) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    
    cout << ans;
    return 0;
}