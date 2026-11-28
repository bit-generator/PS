#include <iostream>
#include <string>
using namespace std;

int T;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    cin.ignore();
    
    while(T--) {
        getline(cin, S);
        int idx = S.find(' ');
        int prv = 0;
        
        while(idx != -1) {
            for(int i = idx - 1; i >= prv; --i)
                cout << S[i];
            cout << ' ';
            prv = idx + 1;
            idx = S.find(' ', prv);
        }
        
        for(int i = S.length() - 1; i >= prv; --i)
            cout << S[i];
        cout << '\n';
    }
    
    return 0;
}