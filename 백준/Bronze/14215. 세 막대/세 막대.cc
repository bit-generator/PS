#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) cin >> arr[i];
    sort(arr, arr + 3);
    if(arr[2] >= arr[0] + arr[1])
        arr[2] = arr[0] + arr[1] - 1;
    
    cout << arr[0] + arr[1] + arr[2];
    return 0;
}