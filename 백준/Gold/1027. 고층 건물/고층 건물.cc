#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int N, ans;
int building[50];
bool isVisible[50][50];

void solve(int lidx, int ridx) {
    isVisible[lidx][ridx] = true;
    isVisible[ridx][lidx] = true;
    
    pair<long long, long long> v1 = {ridx - lidx, building[ridx] - building[lidx]};
    for(int mid = lidx + 1; mid < ridx; ++mid) {
        pair<long long, long long> v2 = {mid - ridx, building[mid] - building[ridx]};
        long long ccw = v1.first * v2.second - v2.first * v1.second;
        if(ccw >= 0) {
            isVisible[lidx][ridx] = false;
            isVisible[ridx][lidx] = false;
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> building[i];
    
    for(int i = 0; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            solve(i, j);
        }
    }
    
    for(int i = 0; i < N; ++i) {
        int tmp = accumulate(isVisible[i], isVisible[i] + N, 0);
        ans = max(ans, tmp);
    }
    
    cout << ans;
    return 0;
}