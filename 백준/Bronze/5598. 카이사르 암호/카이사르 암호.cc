#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] - 3 < 'A') {
            str[i] = str[i] + 23;
        }
        else {
            str[i] -= 3;
        }
    }
    
    cout << str;
    return 0;
}