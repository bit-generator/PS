#include <iostream>
#include <string>
using namespace std;

int T;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> str;
        int idx = str.find("PO");
        while(idx != string::npos) {
            str.replace(idx, 2, "PHO");
            idx = str.find("PO");
        }
        
        cout << str << '\n';
    }
    
    return 0;
}