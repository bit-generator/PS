#include <iostream>
#include <tuple>
using namespace std;

int N, M, S, E, L;
int graph[201][201];
tuple<int, int, int> edges[20000];
double ans = 2'000'001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        cin >> S >> E >> L;
        if(S != E) {
            if(!graph[S][E]) {
                graph[S][E] = L;
                graph[E][S] = L;
            }
            else {
                graph[S][E] = min(graph[S][E], L);
                graph[E][S] = min(graph[E][S], L);
            }
        }
        
        edges[i] = {S, E, L};
    }
    
    for(int k = 1; k <= N; ++k) {
        for(int i = 1; i <= N; ++i) {
            for(int j = 1; j <= N; ++j) {
                if(i == j || !graph[i][k] || !graph[k][j]) continue;
                if(!graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
                else {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    
    for(int k = 1; k <= N; ++k) {
        double tmp = 0;
        
        for(int i = 0; i < M; ++i) {
            tie(S, E, L) = edges[i];
            int longest = max(graph[k][S], graph[k][E]);
            int shortest = min(graph[k][S], graph[k][E]);
            tmp = max(tmp, longest + (double)(shortest + L - longest) / 2); 
        }
        
        ans = min(ans, tmp);
    }
    
    cout << fixed;
    cout.precision(1);
    cout << ans;
    return 0;
}