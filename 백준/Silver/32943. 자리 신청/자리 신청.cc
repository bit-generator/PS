#include <iostream>
#include <algorithm>
using namespace std;

int X, C, K, T, S, N;
tuple<int, int, int> logs[100000];
int seat[100001], student[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> X >> C >> K;
    for(int i = 0; i < K; ++i) {
        cin >> T >> S >> N;
        logs[i] = {T, S, N};
    }
    
    sort(logs, logs + K);
    for(int i = 0; i < K; ++i) {
        S = get<1>(logs[i]);
        N = get<2>(logs[i]);
        if(seat[S] == 0) {
            seat[student[N]] = 0;
            student[N] = S;
            seat[S] = N;
        }
    }
    
    for(int i = 1; i <= X; ++i) {
        if(student[i]) cout << i << ' ' << student[i] << '\n';
    }
    return 0;
}