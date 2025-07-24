#include <iostream>
using namespace std;

int N;
int arr[2][50];
int cnt[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> arr[0][i] >> arr[1][i];
    }
    
    for(int i = 0; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(arr[0][i] > arr[0][j] && arr[1][i] > arr[1][j]) {
                ++cnt[j];
            }
            else if(arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j]) {
                ++cnt[i];
            }
        }
    }
    
    for(int i = 0; i < N; ++i) {
        cout << cnt[i] + 1 << ' ';
    }
    
    return 0;
}