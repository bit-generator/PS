#include <iostream>
using namespace std;

int N, A, B, C;

inline long long fact(int x) {
    if(x <= 1) return 1;
    return x * fact(x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> A >> B >> C;
    cout << fact(N) / (fact(A) * fact(B) * fact(C));
    return 0;
}