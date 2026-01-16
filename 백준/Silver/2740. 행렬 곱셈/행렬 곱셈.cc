#include <iostream>
using namespace std;

int N, M, K;
int A[100][100], B[100][100], ans[100][100];

void solve(int x, int y) {
    for(int i = 0; i < M; ++i) {
        ans[x][y] += (A[x][i] * B[i][y]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    
    cin >> M >> K;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < K; ++j) {
            cin >> B[i][j];
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < K; ++j) {
            solve(i, j);
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < K; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}