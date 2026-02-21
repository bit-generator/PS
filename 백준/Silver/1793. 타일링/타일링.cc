#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
string dp[251];

string operator+(const string& s1, const string& s2) {
    string num1 = s1.length() < s2.length() ? s1 : s2;
    string num2 = s1.length() < s2.length() ? s2 : s1;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    
    int idx = 0, carry = 0;
    string result;
    while(idx < num1.length()) {
        int n1 = num1[idx] - '0';
        int n2 = num2[idx] - '0';
        int sum = n1 + n2 + carry;
        carry = 0;
        if(sum >= 10) {
            carry = 1;
            sum -= 10;
        }

        result += (sum + '0');
        idx++;
    }

    while(carry && idx < num2.length()) {
        int sum = num2[idx++] - '0' + carry;
        carry = 0;
        if(sum >= 10) {
            carry = 1;
            sum -= 10;
        }

        result += (sum + '0');
    }

    if(carry) {
        result += '1';
    }
    else {
        result.append(num2.substr(idx));
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    dp[0] = "1"; dp[1] = "1"; dp[2] = "3";
    for(int i = 3; i <= 250; ++i) {
        dp[i] = dp[i - 2] + dp[i - 2];
        dp[i] = dp[i] + dp[i - 1];
    }
    
    while(cin >> n) {
        cout << dp[n] << '\n';
    }
    
    return 0;
}