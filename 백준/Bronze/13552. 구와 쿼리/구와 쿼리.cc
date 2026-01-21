#include <iostream>
using namespace std;

int N, M;
long long x, y, z, r;
long long point[100000][3];

inline long long pow(long long num) { return num * num; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> point[i][0] >> point[i][1] >> point[i][2];
    }
    
    cin >> M;
    while(M--) {
        cin >> x >> y >> z >> r;
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            long long sum = pow(x - point[i][0]) + pow(y - point[i][1]) + pow(z - point[i][2]);
            if(sum <= pow(r)) ++ans;
        }
        
        cout << ans << '\n';
    }
    return 0;
}