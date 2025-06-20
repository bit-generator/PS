#include <iostream>
#include <string>
using namespace std;

string str;
bool isOdd;
int sum, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(int i = 0; i < 13; ++i) {
        if(str[i] == '*') {
            isOdd = i % 2;
        }
        else {
            sum += ((str[i] - '0') * (1 + 2 * (i % 2)));
        }
    }
    
    for(int i = 0; i < 10; ++i) {
        if((isOdd && (sum + i * 3) % 10 == 0) ||
          (!isOdd && (sum + i) % 10 == 0)) {
            ans = i;
            break;
        }
    }
    
    cout << ans;
    return 0;
}