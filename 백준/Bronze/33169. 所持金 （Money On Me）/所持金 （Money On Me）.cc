#include <iostream>
using namespace std;

int A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B;
    cout << A * 1000 + B * 10000;
    return 0;
}