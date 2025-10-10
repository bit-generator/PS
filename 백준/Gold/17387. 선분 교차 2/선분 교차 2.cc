#include <iostream>
#include <algorithm>
#include <utility>
#define X    first
#define Y    second
using namespace std;

pair<int, int> P[4];

int CCW(int id1, int id2, int id3) {
    long long V1[2] = {P[id2].X - P[id1].X, P[id2].Y - P[id1].Y};
    long long V2[2] = {P[id3].X - P[id1].X, P[id3].Y - P[id1].Y};
    long long cross = V1[0] * V2[1] - V1[1] * V2[0];
    if(cross > 0) return 1;
    else if(cross == 0) return 0;
    else return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 4; ++i) {
        cin >> P[i].X >> P[i].Y;
    }
    
    if(P[0] > P[1]) swap(P[0], P[1]);
    if(P[2] > P[3]) swap(P[2], P[3]);
    
    int ccw[4] = {CCW(0, 1, 2), CCW(0, 1, 3), CCW(2, 3, 0), CCW(2, 3, 1)};
    if(ccw[0] * ccw[1] == 1 || ccw[2] * ccw[3] == 1) cout << 0;
    else {
        if(ccw[0] == 0 && ccw[1] == 0) {
            if((P[0] < P[3] && P[1] < P[2]) || (P[2] < P[1] && P[3] < P[0])) {
                cout << 0;
            }
            else cout << 1;
        }
        else cout << 1;
    }
    
    return 0;
}