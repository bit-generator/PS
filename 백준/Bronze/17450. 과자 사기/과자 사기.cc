#include <iostream>
using namespace std;

int P[3], W[3], type = -1;
double rate[3], maxrate;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) {
        cin >> P[i] >> W[i];
        int discount = (P[i] * 10 >= 5000 ? 50 : 0);
        rate[i] = (double)W[i] / (P[i] - discount);
        if(maxrate < rate[i]) {
            maxrate = rate[i];
            type = i;
        }
    }
    
    if(type == 0) cout << 'S';
    else if(type == 1) cout << 'N';
    else if(type == 2) cout << 'U';
    return 0;
}