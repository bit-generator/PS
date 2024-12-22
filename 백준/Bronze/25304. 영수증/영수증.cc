#include <iostream>
using namespace std;

int X, N, a, b, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> X >> N;
    while(N--) {
        cin >> a >> b;
        sum += (a * b);
    }
    
    if(X == sum) cout << "Yes";
    else cout << "No";
    return 0;
}