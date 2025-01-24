#include <iostream>
#include <algorithm>
#include <tuple>
using namespace std;

int N;
int snowball[600];
tuple<int, int, int> snowman[180000];
int sz;
int ans = 21e8;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> snowball[i];
    
    for(int i = 0; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            snowman[sz++] = {snowball[i] + snowball[j], i, j};
        }
    }
    
    sort(snowman, snowman + sz);
    
    for(int i = 0; i < sz - 1; ++i) {
        for(int j = i + 1; j < sz; ++j) {
            if(get<1>(snowman[i]) == get<1>(snowman[j]) || get<1>(snowman[i]) == get<2>(snowman[j])
              || get<2>(snowman[i]) == get<1>(snowman[j]) || get<2>(snowman[i]) == get<2>(snowman[j])) {
                continue;
            }
            
            int diff = get<0>(snowman[j]) - get<0>(snowman[i]);
            if(diff < ans) {
                ans = diff;
            }
            break;
        }
    }
    
    cout << ans;
    return 0;
}