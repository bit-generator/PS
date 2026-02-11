#include <iostream>
using namespace std;

int A, B, C, D;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B >> C >> D;
    if(A + C < B + D) cout << "Hanyang Univ.";
    else if(A + C > B + D) cout << "Yongdap";
    else cout << "Either";
    return 0;
}