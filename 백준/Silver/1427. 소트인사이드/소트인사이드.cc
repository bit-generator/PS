#include <iostream>
#include <string>
using namespace std;

int cnt[10];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(char c : str) {
        ++cnt[c - '0'];
    }
    
    for(int i = 9; i >= 0; --i) {
        for(int j = 0; j < cnt[i]; ++j) {
            cout << i;
        }
    }
    
    return 0;
}