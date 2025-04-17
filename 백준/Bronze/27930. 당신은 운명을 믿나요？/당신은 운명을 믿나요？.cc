#include <iostream>
#include <string>
using namespace std;

int idx1, idx2;
string str;
string str1 = "KOREA", str2 = "YONSEI";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(const char& c : str) {
        if(str1[idx1] == c) ++idx1;
        if(idx1 == 5) {
            cout << str1;
            break;
        }
        
        if(str2[idx2] == c) ++idx2;
        if(idx2 == 6) {
            cout << str2;
            break;
        }
    }
    
    return 0;
}