#include <iostream>
#include <string>
using namespace std;

int N, ans;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> str;
    for(int i = 0; i < N; ++i) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
          || str[i] == 'o' || str[i] == 'u') ans++;
    }
    
    cout << ans;
    return 0;
}