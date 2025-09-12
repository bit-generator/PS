#include <iostream>
using namespace std;

int N;
int arr[5000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; i += 2) {
        arr[i] = (N >> 1) + (i >> 1) + 1;
    }
    
    for(int i = 1; i < N; i += 2) {
        arr[i] = (i >> 1) + 1;
    }
    
    for(int i = 0; i < N; ++i) cout << arr[i] << ' ';
    return 0;
}