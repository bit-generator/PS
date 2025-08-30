#include <iostream>
#include <string>
using namespace std;

int H, R = 2, del;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H;
    for(int i = 0; i < H; ++i) R <<= 1;
    --R;
    
    if(cin >> str) {
        for(int i = 0; i < str.length(); ++i) {
            int tmp = del;
            if(str[i] == 'L') {
                tmp += 1;
            }
            else {
                tmp += 2;
            }
            
            R -= tmp;
            del += tmp;
        }
    }
    
    cout << R;
    return 0;
}