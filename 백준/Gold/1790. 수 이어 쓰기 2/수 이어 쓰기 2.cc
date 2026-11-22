#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, k;
    cin >> N >> k;
    
    int start = 1, base = 9, digit = 1;
    
    while((long long)start * base * digit < k) {
        k -= (start * base * digit++);
        start *= 10;
    }
    
    int num = (k - 1) / digit;
    if(start + num > N) {
        cout << -1;
        return 0;
    }
    
    int id = (k - 1) % digit;
    cout << to_string(start + num)[id];
    return 0;
}