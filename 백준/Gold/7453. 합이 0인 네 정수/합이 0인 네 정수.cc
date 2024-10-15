#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long ans;
int A[4000], B[4000], C[4000], D[4000];
int sum1[16000000], sum2[16000000];
int sum1_size, sum2_size;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            sum1[sum1_size++] = A[i] + B[j];
            sum2[sum2_size++] = C[i] + D[j];
        }
    }
    
    sort(sum1, sum1 + sum1_size);
    for(int i = 0; i < sum2_size; i++) {
        auto it = lower_bound(sum1, sum1 + sum1_size, -sum2[i]);
        if(it - sum1 != sum1_size && *it == -sum2[i]) {
            auto it2 = upper_bound(sum1, sum1 + sum1_size, -sum2[i]);
            ans += (it2 - it);
        }
    }
    
    cout << ans;
    return 0;
}