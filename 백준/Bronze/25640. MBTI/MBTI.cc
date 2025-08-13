#include <iostream>
#include <string>
using namespace std;

int N, ans;
string str1, str2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str1 >> N;
    while(N--) {
        cin >> str2;
        if(str1 == str2) ++ans;
    }
    
    cout << ans;
    return 0;
}