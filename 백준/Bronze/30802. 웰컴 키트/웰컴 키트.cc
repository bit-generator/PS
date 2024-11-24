#include <iostream>
using namespace std;

int N, T, P;
int arr[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < 6; i++) cin >> arr[i];
    cin >> T >> P;
    
    int cnt = 0;
    for(int i = 0; i < 6; i++) {
        cnt += ((arr[i] + T - 1) / T);
    }
    
    cout << cnt << '\n';
    cout << N / P << ' ' << N % P;
    
    return 0;
}