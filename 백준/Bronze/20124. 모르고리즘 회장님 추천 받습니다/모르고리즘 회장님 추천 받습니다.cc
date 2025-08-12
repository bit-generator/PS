#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int N;
pair<string, int> arr[100000];

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> arr[i].first >> arr[i].second;
    sort(arr, arr + N, compare);
    cout << arr[0].first;
    return 0;
}