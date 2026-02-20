#include <iostream>
#include <string>
using namespace std;

string str;
char ch[5] = {'K', 'O', 'R', 'E', 'A'};
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == ch[ans % 5]) ++ans;
    }
    
    cout << ans;
    return 0;
}