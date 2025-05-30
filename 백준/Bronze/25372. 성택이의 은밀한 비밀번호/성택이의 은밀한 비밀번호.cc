#include <iostream>
#include <string>
using namespace std;

int N;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> str;
        if(str.length() >= 6 && str.length() <= 9) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
    
    return 0;
}