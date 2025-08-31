#include <iostream>
#include <string>
#include <numeric>
using namespace std;

int N, K;
string nums[15];
long long dp[1 << 15][100];
int tenmod[51];
int numsmod[15];

long long factorial(int n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> nums[i];
    cin >> K;
    
    for(int i = 0; i < N; ++i) {
        int tmp = 0;
        
        for(int j = 0; j < nums[i].length(); ++j) {
            tmp = (tmp * 10 + (nums[i][j] - '0')) % K;
        }
        
        ++dp[1 << i][tmp];
        numsmod[i] = tmp;
    }
    
    tenmod[0] = 1;
    for(int i = 1; i <= 50; ++i) {
        tenmod[i] = (tenmod[i - 1] * 10) % K;
    }
    
    for(int i = 1; i < (1 << N); ++i) {
        for(int j = 0; j < N; ++j) {
            if(i & (1 << j)) continue;
            
            for(int k = 0; k < K; ++k) {
                if(!dp[i][k]) continue;
                int mod = (k * tenmod[nums[j].length()] + numsmod[j]) % K;
                dp[i | (1 << j)][mod] += dp[i][k];
            }
        }
    }
    
    long long fact = factorial(N);
    long long divnum = gcd(fact, dp[(1 << N) - 1][0]);
    cout << dp[(1 << N) - 1][0] / divnum << '/' << fact / divnum;
    return 0;
}