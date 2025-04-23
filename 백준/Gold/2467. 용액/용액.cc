#include <iostream>
#include <cstdlib>
#include <utility>
using namespace std;

int N, minval = 2'000'000'000;
int liquid[100000];
pair<int, int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> liquid[i];
    
    int id1 = 0, id2 = N - 1;
    while(id1 < id2) {
        int sum = liquid[id1] + liquid[id2];
        if(abs(sum) < minval) {
            minval = abs(sum);
            ans = {liquid[id1], liquid[id2]};
        }
        
        if(sum > 0) id2--;
        else id1++;
    }
    
    cout << ans.first << ' ' << ans.second;
    return 0;
}