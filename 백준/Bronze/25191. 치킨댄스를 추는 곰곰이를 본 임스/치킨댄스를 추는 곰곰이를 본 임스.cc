#include <iostream>
using namespace std;

int N, A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> A >> B;
    A /= 2;
    
    if(N <= A + B) cout << N;
    else cout << A + B;
    return 0;
}