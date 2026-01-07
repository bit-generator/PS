#include <iostream>
using namespace std;

int W, H;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> W >> H;
    cout << fixed;
    cout.precision(1);
    cout << (double)W * H / 2;
    
    return 0;
}