#include <iostream>
#include <string>
using namespace std;

string str;
string target[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    
    for(int i = 0; i < 8; i++) {
        int pos = str.find(target[i]);
        
        while(pos != -1) {
            str.replace(pos, target[i].length(), "#");
            pos = str.find(target[i]);
        }
    }
    
    cout << str.length();
    return 0;
}