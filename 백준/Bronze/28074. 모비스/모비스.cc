#include <iostream>
#include <string>
using namespace std;

string str;
bool flag[5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(char c : str) {
        if(c == 'M') flag[0] = true;
        else if(c == 'O') flag[1] = true;
        else if(c == 'B') flag[2] = true;
        else if(c == 'I') flag[3] = true;
        else if(c == 'S') flag[4] = true;
    }
    
    if(flag[0] && flag[1] && flag[2] && flag[3] && flag[4]) cout << "YES";
    else cout << "NO";
    return 0;
}