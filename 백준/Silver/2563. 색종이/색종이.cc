#include <iostream>
using namespace std;

int N, X, Y, ans;
bool arr[100][100];

void arrfill(int x, int y) {
    for(int i = x; i < x + 10; ++i) {
        for(int j = y; j < y + 10; ++j) {
            arr[i][j] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> X >> Y;
        arrfill(X, Y);
    }
    
    for(int i = 0; i < 100; ++i) {
        for(int j = 0; j < 100; ++j) {
            ans += arr[i][j];
        }
    }
    
    cout << ans;
    return 0;
}