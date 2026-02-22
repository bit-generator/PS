#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N;
pair<int, int> arr[100];
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + N);
    
    for(int i = 0; i < N; ++i) {
        auto it = lower_bound(v.begin(), v.end(), arr[i].second);
        if(it == v.end()) v.push_back(arr[i].second);
        else *it = arr[i].second;
    }
    
    cout << N - v.size();
    return 0;
}