#include <iostream>
#include <string>
using namespace std;

bool found;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 1; i <= 5; i++) {
        cin >> str;
        if(str.find("FBI") != -1) {
            cout << i << ' ';
            found = true;
        }
    }
    
    if(!found) cout << "HE GOT AWAY!";
    return 0;
}