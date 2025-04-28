#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string str;
int dp[500][500];

int solve(int start, int last) {
    if(start >= last) {
        return dp[start][last] = 0;
    }
    
    if(dp[start][last] != -1) return dp[start][last];
    
    for(int i = start; i < last; ++i) {
        dp[start][last] = max(dp[start][last], solve(start, i) + solve(i + 1, last));
    }
    
    if((str[start] == 'a' && str[last] == 't') ||
       (str[start] == 'g' && str[last] == 'c')) {
        dp[start][last] = max(dp[start][last], solve(start + 1, last - 1) + 2);
    }
    
    return dp[start][last];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    memset(dp, -1, sizeof(dp));
    cout << solve(0, str.length() - 1);
    return 0;
}