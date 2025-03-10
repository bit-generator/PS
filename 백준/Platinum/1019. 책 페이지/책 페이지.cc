#include <iostream>
using namespace std;

int N;
long long ans[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    int tens = 1;
    int origin = N;
    
    while(N > 0) {
        int digit = N % 10;
        int leftover = N / 10;
        
        for(int i = 0; i <= 9; ++i) {
            ans[i] += leftover * tens;
        }
        
        for(int i = 0; i < digit; ++i) ans[i] += tens;
        ans[digit] += (origin % tens) + 1;
        ans[0] -= tens;
        
        N /= 10;
        tens *= 10;
    }
    
    for(int i = 0; i <= 9; ++i) cout << ans[i] << ' ';
    return 0;
}