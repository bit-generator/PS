#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int n;
int arr[11];
int opr[4];
int order[10];
pair<int, int> ans = {0x80000000, 0x7fffffff};

void solve() {
    int result = arr[0];
    for(int i = 0; i < n - 1; i++) {
        switch(order[i]) {
            case 0:
                result += arr[i + 1];
                break;
            case 1:
                result -= arr[i + 1];
                break;
            case 2:
                result *= arr[i + 1];
                break;
            case 3:
                result /= arr[i + 1];
                break;
        }
    }

    ans.first = max(ans.first, result);
    ans.second = min(ans.second, result);
}

void backtrack(int cnt) {
    if(cnt == n - 1) {
        solve();
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        if(opr[i] == 0) continue;
        order[cnt] = i;
        opr[i]--;
        backtrack(cnt + 1);
        opr[i]++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int tmp, k = 0;
    for(int i = 0; i < 4; i++) {
        cin >> opr[i];
    }
    
    backtrack(0);
    
    cout << ans.first << '\n' << ans.second;
    return 0;
}