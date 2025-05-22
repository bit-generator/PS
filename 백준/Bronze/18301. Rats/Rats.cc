#include <iostream>
using namespace std;

int n1, n2, n12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n1 >> n2 >> n12;
    cout << (n1 + 1) * (n2 + 1) / (n12 + 1) - 1;
    
    return 0;
}