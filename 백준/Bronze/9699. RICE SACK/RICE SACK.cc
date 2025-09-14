#include <iostream>
using namespace std;

int N;
int num, mx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        mx = 0;
        for(int j = 0; j < 5; ++j) {
            cin >> num;
            if(mx < num) mx = num;
        }
        
        cout << "Case #" << i << ": " << mx << '\n';
    }
    
    return 0;
}