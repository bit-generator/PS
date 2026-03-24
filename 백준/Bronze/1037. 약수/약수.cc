#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    cout << arr[0] * arr[N - 1];
    return 0;
}