#include <iostream>
#include <string>
using namespace std;

int T, X, N, K, A;
string ans = "YES";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T >> X >> N;
    while(N--) {
        cin >> K;
        bool check = false;
        while(K--) {
            cin >> A;
            if(A == X) check = true;
        }
        
        if(!check) ans = "NO";
    }
    
    cout << ans;
    return 0;
}