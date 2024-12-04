#include <iostream>
using namespace std;

int N;

int getSum(int x) {
    int sum = 0;
    while(x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    
    for(int i = 1; i < N; ++i) {
        if(i + getSum(i) == N) {
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
    return 0;
}