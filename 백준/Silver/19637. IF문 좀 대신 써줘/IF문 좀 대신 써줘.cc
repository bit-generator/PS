#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M, K;
string medal[100000];
int arr[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> medal[i] >> arr[i];
    }
    
    while(M--) {
        cin >> K;
        int key = lower_bound(arr, arr + N, K) - arr;
        cout << medal[key] << '\n';
    }
    
    return 0;
}