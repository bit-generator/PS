#include <iostream>
using namespace std;

int N, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int a = 1; a <= 500; ++a) {
        for(int b = 1; b <= 500; ++b) {
            if(a * a == b * b + N) ++ans;
        }
    }
    
    cout << ans;
    return 0;
}