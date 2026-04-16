#include <iostream>
#include <unordered_set>
using namespace std;

int n;
int arr[7];
unordered_set<int> us;

void backtrack(int cnt) {
    if(cnt >= n) {
        int times = 1;
        for(int i = 0; i < n; ++i) {
            times *= arr[i];
        }
        
        us.insert(times);
        return;
    }
    
    for(int i = 1; i <= 9; ++i) {
        if(cnt > 0 && arr[cnt - 1] > i)
            continue;
        
        arr[cnt] = i;
        backtrack(cnt + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    backtrack(0);
    cout << us.size();
    return 0;
}