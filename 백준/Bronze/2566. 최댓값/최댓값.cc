#include <iostream>
using namespace std;

int tmp, r, c;
int maxVal = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i <= 9; ++i) {
        for(int j = 1; j <= 9; ++j) {
            cin >> tmp;
            if(tmp > maxVal) {
                maxVal = tmp;
                r = i;
                c = j;
            }
        }
    }
    
    cout << maxVal << '\n' << r << ' ' << c;
    return 0;
}