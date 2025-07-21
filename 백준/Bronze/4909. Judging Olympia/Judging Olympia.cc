#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int arr[6];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        for(int i = 0; i < 6; ++i) cin >> arr[i];
        sort(arr, arr + 6);
        if(arr[5] == 0) break;
        
        int ans = accumulate(arr + 1, arr + 5, 0);
        cout << (double)ans / 4 << '\n';
    }
    
    return 0;
}