#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[101];
bool visit[101];
bool check[101];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    
    for(int i = 1; i <= N; ++i) {
        if(visit[i]) continue;
        visit[i] = true;
        int pos = arr[i];
        
        while(!visit[pos]) {
            visit[pos] = true;
            pos = arr[pos];
        }
        
        while(!check[pos]) {
            check[pos] = true;
            ans.push_back(pos);
            pos = arr[pos];
        }
        
        pos = i;
        while(!check[pos]) {
            check[pos] = true;
            pos = arr[pos];
        }
    }
    
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto n : ans) cout << n << '\n';
    return 0;
}