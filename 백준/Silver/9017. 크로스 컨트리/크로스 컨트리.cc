#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int T, N, M, scorecnt;
int arr[1000], cnt[201], sum[201], fifth[201];
vector<tuple<int, int, int>> sorted;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> N;
        M = 0, scorecnt = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        sorted.clear();
        
        for(int i = 0; i < N; ++i) {
            cin >> arr[i];
            ++cnt[arr[i]];
            M = max(M, arr[i]);
        }
        
        for(int i = 0; i < N; ++i) {
            if(cnt[arr[i]] < 6) continue;
            ++scorecnt;
            if(++cnt[arr[i]] <= 10) sum[arr[i]] += scorecnt;
            if(cnt[arr[i]] == 11) fifth[arr[i]] = scorecnt;
        }
        
        for(int i = 1; i <= M; ++i) {
            if(sum[i] != 0) sorted.emplace_back(sum[i], fifth[i], i);
        }
        
        sort(sorted.begin(), sorted.end());
        cout << get<2>(sorted[0]) << '\n';
    }
    
    return 0;
}