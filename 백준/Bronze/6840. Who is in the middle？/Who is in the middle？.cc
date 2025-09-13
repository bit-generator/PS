#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    cout << arr[1];
    return 0;
}