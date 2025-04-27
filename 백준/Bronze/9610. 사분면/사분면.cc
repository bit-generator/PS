#include <iostream>
using namespace std;

int n, x, y;
int ans[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    while(n--) {
        cin >> x >> y;
        if(x > 0 && y > 0) ++ans[1];
        else if(x < 0 && y > 0) ++ans[2];
        else if(x < 0 && y < 0) ++ans[3];
        else if(x > 0 && y < 0) ++ans[4];
        else ++ans[0];
    }
    
    for(int i = 1; i <= 4; ++i) {
        cout << 'Q' << i << ": " << ans[i] << '\n';
    }
    cout << "AXIS: " << ans[0];
    
    return 0;
}