#include <iostream>
using namespace std;

int T, C;
int unit[4] = {25, 10, 5, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> C;
        for(int i = 0; i < 4; ++i) {
            cout << C / unit[i] << ' ';
            C %= unit[i];
        }
        cout << '\n';
    }
    
    return 0;
}