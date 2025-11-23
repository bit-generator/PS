#include <iostream>
#include <algorithm>
using namespace std;

int N;
int road[99999];
long long cost[100000];
long long ans, minCost = 1'000'000'001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N - 1; ++i) cin >> road[i];
    for(int i = 0; i < N; ++i) cin >> cost[i];
    
    for(int i = 0; i < N - 1; ++i) {
        minCost = min(minCost, cost[i]);
        ans += (minCost * road[i]);
    }
    
    cout << ans;
    return 0;
}