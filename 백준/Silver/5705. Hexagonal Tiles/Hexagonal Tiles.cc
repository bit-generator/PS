#include <iostream>
using namespace std;

int N;
int arr[41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    arr[1] = 1;
    arr[2] = 2;
    for(int i = 3; i <= 40; ++i) arr[i] = arr[i - 1] + arr[i - 2];
    
    while(true) {
        cin >> N;
        if(N == 0) break;
        cout << arr[N] << '\n';
    }
    
    return 0;
}