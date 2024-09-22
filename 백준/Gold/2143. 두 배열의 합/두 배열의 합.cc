#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, n, m;
long long ans;
int A[1001], B[1001];
vector<int> sumA, sumB;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T >> n;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        A[i] += A[i - 1];
        
        for(int j = 0; j < i; j++) {
            sumA.push_back(A[i] - A[j]);
        }
    }
    
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> B[i];
        B[i] += B[i - 1];
        
        for(int j = 0; j < i; j++) {
            sumB.push_back(B[i] - B[j]);
        }
    }
    
    sort(sumA.begin(), sumA.end());
    for(int i = 0; i < sumB.size(); i++) {
        int cnt = upper_bound(sumA.begin(), sumA.end(), T - sumB[i])
            - lower_bound(sumA.begin(), sumA.end(), T - sumB[i]);
        ans += cnt;
    }
    
    cout << ans;
    return 0;
}