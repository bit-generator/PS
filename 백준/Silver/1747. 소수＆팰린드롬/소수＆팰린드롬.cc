#include <iostream>
using namespace std;

constexpr int MAX_SIZE = 10'000'000;
constexpr bool NOT_PRIME = true;
int N, ans;
int arr[1000001];
bool prime[MAX_SIZE];
int digit[10];

bool isPalindrome(int x) {
    int tmp = x;
    int pos = 0, tens = 1;
    digit[pos++] = tmp % 10;
    tmp /= 10;
    
    while(tmp > 0) {
        digit[pos++] = tmp % 10;
        tmp /= 10;
        tens *= 10;
    }
    
    int sum = 0;
    for(int i = 0; i < pos; i++) {
        sum += (digit[i] * tens);
        tens /= 10;
    }
    
    if(x == sum) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    prime[1] = NOT_PRIME;
    for(int i = 2; i * i < MAX_SIZE; i++) {
        if(prime[i] == NOT_PRIME) continue;
        for(int j = i * 2; j < MAX_SIZE; j += i) {
            prime[j] = NOT_PRIME;
        }
    }
    
    for(int i = N; ; i++) {
        if(prime[i] == NOT_PRIME) continue;
        if(isPalindrome(i)) {
            ans = i;
            break;
        }
    }
    
    cout << ans;
    return 0;
}