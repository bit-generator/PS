#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, B;
string ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> B;
    while(N > 0) {
        int mod = N % B;
        char ch = mod + '0';
        if(mod >= 10) ch = mod - 10 + 'A';
        ans += ch;
        N /= B;
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}