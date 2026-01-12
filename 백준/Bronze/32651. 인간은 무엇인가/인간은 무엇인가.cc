#include <iostream>
using namespace std;

int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    if(N <= 100000 && N % 2024 == 0) cout << "Yes";
    else cout << "No";
    return 0;
}