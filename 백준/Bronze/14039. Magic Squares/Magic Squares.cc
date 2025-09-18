#include <iostream>
#include <numeric>
using namespace std;

int arr[5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            cin >> arr[i][j];
        }
        
        arr[i][4] = accumulate(arr[i], arr[i] + 4, 0);
    }
    
    for(int i = 0; i < 4; ++i) {
        arr[4][i] = arr[0][i] + arr[1][i] + arr[2][i] + arr[3][i];
        if(arr[0][4] != arr[i][4] || arr[0][4] != arr[4][i]) {
            cout << "not magic";
            return 0;
        }
    }
    
    cout << "magic";
    return 0;
}