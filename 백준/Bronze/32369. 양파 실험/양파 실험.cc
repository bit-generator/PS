#include <iostream>
using namespace std;

int N, A, B;
int o1 = 1, o2 = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> A >> B;
    while(N--) {
        o1 += A; o2 += B;
        if(o1 < o2) {
            int tmp = o1;
            o1 = o2;
            o2 = tmp;
        }
        else if(o1 == o2) {
            --o2;
        }
    }
    
    cout << o1 << ' ' << o2;
    return 0;
}