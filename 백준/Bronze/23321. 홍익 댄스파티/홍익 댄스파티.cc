#include <iostream>
using namespace std;

char arr[5][10001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 5; ++i) {
        cin >> arr[i];
    }
    
    for(int i = 0; arr[0][i] != 0; ++i) {
        if(arr[0][i] == 'o') {
            arr[0][i] = '.'; arr[1][i] = 'o'; arr[2][i] = 'm';
            arr[3][i] = 'l'; arr[4][i] = 'n';
        }
        else if(arr[1][i] == 'o') {
            arr[0][i] = 'o'; arr[1][i] = 'w'; arr[2][i] = 'l';
            arr[3][i] = 'n'; arr[4][i] = '.';
        }
    }
    
    for(int i = 0; i < 5; ++i) {
        cout << arr[i] << '\n';
    }
    
    return 0;
}