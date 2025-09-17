#include <iostream>
using namespace std;

int A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> A >> B;
        if(A == 0 && B == 0) break;
        
        if(A < B && B % A == 0) cout << "factor";
        else if(A > B && A % B == 0) cout << "multiple";
        else cout << "neither";
        cout << '\n';
    }
    
    return 0;
}