#include <iostream>
using namespace std;

int P[4][2];

int CCW(int id1, int id2, int id3) {
    int V1[2] = {P[id2][0] - P[id1][0], P[id2][1] - P[id1][1]};
    int V2[2] = {P[id3][0] - P[id1][0], P[id3][1] - P[id1][1]};
    int cross = V1[0] * V2[1] - V1[1] * V2[0];
    if(cross > 0) return 1;
    else if(cross == 0) return 0;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 4; ++i) {
        cin >> P[i][0] >> P[i][1];
    }
    
    if(CCW(0, 1, 2) * CCW(0, 1, 3) == -1 && CCW(2, 3, 0) * CCW(2, 3, 1) == -1) {
        cout << 1;
    }
    else cout << 0;
    
    return 0;
}