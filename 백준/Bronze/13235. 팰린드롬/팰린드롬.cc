#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    int len = (str.length() + 1) / 2;
    
    for(int i = 0; i < len; ++i) {
        if(str[i] != str[str.length() - i - 1]) {
            cout << "false";
            return 0;
        }
    }
    
    cout << "true";
    return 0;
}