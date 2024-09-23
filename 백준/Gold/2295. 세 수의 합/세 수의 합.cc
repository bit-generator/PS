#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
vector<int> sum;
int ans;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            sum.push_back(arr[i] + arr[j]);
        }
    }
    sort(sum.begin(), sum.end());
    
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(binary_search(sum.begin(), sum.end(), arr[i] - arr[j])) {
                cout << arr[i];
                return 0;
            }
        }
    }

    return 0;
}