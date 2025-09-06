#include <iostream>
#include <algorithm>
using namespace std;

int N, M, B, H, totalH;
int hCnt[257], maxH, minH = 256;
int ans = 0x7FFFFFFF, ansH;

int getCost(int x) {
    int ret = 0;
    for(int i = maxH; i > x; --i) {
        ret += ((i - x) * hCnt[i] * 2); 
    }
    
    for(int i = minH; i < x; ++i) {
        ret += ((x - i) * hCnt[i]);
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M >> B;
    for(int i = 0; i < N * M; ++i) {
        cin >> H;
        ++hCnt[H];
        totalH += H;
        maxH = max(H, maxH);
        minH = min(H, minH);
    }
    
    int upperBound = min(256, (totalH + B) / (N * M));
    for(int i = 0; i <= upperBound; ++i) {
        int cost = getCost(i);
        if(cost <= ans) {
            ans = cost;
            ansH = i;
        }
    }
    
    cout << ans << ' ' << ansH;
    return 0;
}