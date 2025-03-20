#include <iostream>
using namespace std;

int n;
long long a, b, prv = 1;
char op;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    while(n--) {
        cin >> a >> op >> b;
        if(op == '+') {
            prv = a + b - prv;
        }
        else if(op == '-') {
            prv = (a - b) * prv;
        }
        else if(op == '*') {
            prv = a * a * b * b;
        }
        else {
            prv = (a % 2 ? a + 1 : a) >> 1;
        }
        
        cout << prv << '\n';
    }
    
    return 0;
}