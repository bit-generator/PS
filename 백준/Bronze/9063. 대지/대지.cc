#include <iostream>
#include <algorithm>
using namespace std;

int N, X, Y, minX = 10001, minY = 10001, maxX = -10001, maxY = -10001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> X >> Y;
        minX = min(minX, X);
        minY = min(minY, Y);
        maxX = max(maxX, X);
        maxY = max(maxY, Y);
    }
    
    cout << (maxX - minX) * (maxY - minY);
    return 0;
}