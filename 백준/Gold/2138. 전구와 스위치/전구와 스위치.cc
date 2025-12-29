#include <iostream>
#include <algorithm>
using namespace std;

int N, ans = 1'000'000'000;
bool arr1[100001], arr2[100001], copied[100001];
char ch;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> ch;
        if(ch == '1') {
            arr1[i] = true;
            copied[i] = true;
        }
    }
    
    for(int i = 0; i < N; ++i) {
        cin >> ch;
        if(ch == '1') arr2[i] = true;
    }
    
    int cnt = 0;
    for(int i = 1; i < N; ++i) {
        if(copied[i - 1] != arr2[i - 1]) {
            copied[i - 1] = !copied[i - 1];
            copied[i] = !copied[i];
            copied[i + 1] = !copied[i + 1];
            ++cnt;
        }
    }
    
    if(copied[N - 1] == arr2[N - 1]) ans = cnt;
    
    for(int i = 0; i < N; ++i) copied[i] = arr1[i];
    copied[0] = !copied[0];
    copied[1] = !copied[1];
    cnt = 1;
    
    for(int i = 1; i < N; ++i) {
        if(copied[i - 1] != arr2[i - 1]) {
            copied[i - 1] = !copied[i - 1];
            copied[i] = !copied[i];
            copied[i + 1] = !copied[i + 1];
            ++cnt;
        }
    }
    
    if(copied[N - 1] == arr2[N - 1]) ans = min(ans, cnt);
    if(ans == 1'000'000'000) cout << -1;
    else cout << ans;
    return 0;
}