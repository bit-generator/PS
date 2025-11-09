#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#define X    first
#define Y    second
#define PI    3.141592
using namespace std;
using pll = pair<long long, long long>;

int N, L;
pll P[1000];
vector<int> st;
double ans;

bool yfirst(const pll& a, const pll& b) {
    if(a.Y == b.Y) return a.X < b.X;
    return a.Y < b.Y;
}

inline long long pow(long long x) { return x * x; }

inline long long dist(const pll& p1, const pll& p2) {
    return pow(p2.X - p1.X) + pow(p2.Y - p1.Y);
}

long long ccw(const pll& p1, const pll& p2, const pll& p3) {
    pll v1 = {p2.X - p1.X, p2.Y - p1.Y};
    pll v2 = {p3.X - p1.X, p3.Y - p1.Y};
    return v1.X * v2.Y - v2.X * v1.Y;
}

bool ccwfirst(const pll& a, const pll& b) {
    long long tmp = ccw(P[0], a, b);
    if(tmp == 0) return dist(P[0], a) < dist(P[0], b);
    return tmp > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> L;
    for(int i = 0; i < N; ++i) cin >> P[i].X >> P[i].Y;
    sort(P, P + N, yfirst);
    sort(P + 1, P + N, ccwfirst);
    
    st.push_back(0);
    st.push_back(1);
    for(int i = 2; i < N; ++i) {
        while(st.size() >= 2) {
            int idx1 = st[st.size() - 2];
            int idx2 = st[st.size() - 1];
            if(ccw(P[idx1], P[idx2], P[i]) <= 0) st.pop_back();
            else break;
        }
        
        st.push_back(i);
    }
    
    int sz = st.size();
    for(int i = 0; i < sz; ++i) {
        int idx1 = st[i];
        int idx2 = st[(i + 1) % sz];
        ans += sqrt(dist(P[idx1], P[idx2]));
    }
    
    ans += (2 * L * PI);
    cout << (int)(ans + 0.5);
    return 0;
}