#include <iostream>
using namespace std;

int N, sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 10; ++i) {
        cin >> N;
        sum += N;
    }
    
    cout << (sum >> 1);
    return 0;
}