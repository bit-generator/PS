#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> arr[j];
        }
        sort(arr, arr + 3);
        
        cout << "Scenario #" << i << ":\n";
        if(arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
        cout << '\n';
    }
    
    return 0;
}