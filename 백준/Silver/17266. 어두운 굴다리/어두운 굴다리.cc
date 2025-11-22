#include <iostream>
using namespace std;

int N, M, ans;
int light[100000];

bool solve(int target) {
    int upbound = 0;
    for(int i = 0; i < M; ++i) {
        int range_min = light[i] - target;
        int range_max = light[i] + target;
        if(upbound < range_min) {
            return false;
        }
        
        upbound = range_max;
    }
    
    if(upbound < N) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < M; ++i) cin >> light[i];
    
    int start = 1, last = 100000;
    while(start <= last) {
        int mid = (start + last) / 2;
        if(solve(mid)) {
            last = mid - 1;
            ans = mid;
        }
        else {
            start = mid + 1;
        }
    }
    
    cout << ans;
    return 0;
}