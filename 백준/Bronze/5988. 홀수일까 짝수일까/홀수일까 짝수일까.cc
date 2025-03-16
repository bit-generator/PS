#include <iostream>
#include <string>
using namespace std;

int N;
string K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> K;
        if((K[K.length() - 1] - '0') % 2) {
            cout << "odd\n";
        }
        else {
            cout << "even\n";
        }
    }
    
    return 0;
}