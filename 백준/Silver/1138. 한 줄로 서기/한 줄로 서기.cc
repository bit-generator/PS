#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[11];
bool check[11];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    
    for(int i = 0; i < N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(arr[j] > ans.size() || check[j]) continue;
            
            int cnt = 0;
            for(int x : ans) {
                if(x > j) ++cnt;
            }
            
            if(cnt == arr[j]) {
                ans.push_back(j);
                check[j] = true;
                break;
            }
        }
    }
    
    for(int x : ans) {
        cout << x << ' ';
    }
    return 0;
}