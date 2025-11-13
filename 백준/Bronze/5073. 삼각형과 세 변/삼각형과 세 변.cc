#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        for(int i = 0; i < 3; ++i) cin >> arr[i];
        if(arr[0] == 0) break;
        
        sort(arr, arr + 3);
        if(arr[0] + arr[1] <= arr[2]) {
            cout << "Invalid\n";
        }
        else {
            if(arr[0] == arr[2]) cout << "Equilateral\n";
            else if(arr[0] == arr[1] || arr[1] == arr[2]) cout << "Isosceles\n";
            else cout << "Scalene\n";
        }
    }
    
    return 0;
}