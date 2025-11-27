#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K, ans;
string str;
bool check[20000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K >> str;
    for(int i = 0; i < N; ++i) {
        if(str[i] == 'H') continue;
        
        for(int j = max(i - K, 0); j <= min(N - 1, i + K); ++j) {
            if(str[j] == 'H' && !check[j]) {
                ++ans;
                check[j] = true;
                break;
            }
        }
    }
    
    cout << ans;
    return 0;
}