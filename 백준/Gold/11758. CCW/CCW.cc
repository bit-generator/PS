#include <iostream>
using namespace std;

int P[3][2];
int V1[2], V2[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 3; ++i) {
        cin >> P[i][0] >> P[i][1];
    }
    
    for(int i = 0; i < 2; ++i) {
        V1[i] = P[1][i] - P[0][i];
        V2[i] = P[2][i] - P[1][i];
    }
    
    int cross_product = V1[0] * V2[1] - V1[1] * V2[0];
    if(cross_product > 0) cout << 1;
    else if(cross_product == 0) cout << 0;
    else cout << -1;
    
    return 0;
}