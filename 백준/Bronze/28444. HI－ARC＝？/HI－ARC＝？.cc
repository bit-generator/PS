#include <iostream>
using namespace std;

int H, I, A, R, C;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H >> I >> A >> R >> C;
    cout << H * I - A * R * C;
    return 0;
}