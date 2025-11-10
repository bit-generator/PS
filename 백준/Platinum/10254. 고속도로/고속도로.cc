#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define X    first
#define Y    second
using namespace std;
using pll = pair<long long, long long>;

int T, n;
pll P[200000];
vector<int> st;
pll ans1, ans2;

inline long long pow(long long x) { return x * x; }

bool yfirst(const pll& a, const pll& b) {
    if(a.Y == b.Y) return a.X < b.X;
    return a.Y < b.Y;
}

inline long long ccw(const pll& v1, const pll& v2) {
    return v1.X * v2.Y - v2.X * v1.Y;
}

inline long long dist(const pll& p1, const pll& p2) {
    return pow(p2.X - p1.X) + pow(p2.Y - p1.Y);
}

bool ccwfirst(const pll& a, const pll& b) {
    pll v1 = {a.X - P[0].X, a.Y - P[0].Y};
    pll v2 = {b.X - P[0].X, b.Y - P[0].Y};
    long long tmp = ccw(v1, v2);
    if(tmp == 0) return dist(P[0], a) < dist(P[0], b);
    return tmp > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> P[i].X >> P[i].Y;
        sort(P, P + n, yfirst);
        sort(P + 1, P + n, ccwfirst);
        
        st.clear();
        st.push_back(0);
        st.push_back(1);
        for(int i = 2; i < n; ++i) {
            while(st.size() >= 2) {
                int idx1 = st[st.size() - 2];
                int idx2 = st[st.size() - 1];
                pll v1 = {P[idx2].X - P[idx1].X, P[idx2].Y - P[idx1].Y};
                pll v2 = {P[i].X - P[idx1].X, P[i].Y - P[idx1].Y};
                if(ccw(v1, v2) <= 0) st.pop_back();
                else break;
            }
            
            st.push_back(i);
        }
        
        int idx1 = 0, idx2 = 1;
        int sz = st.size();
        long long mx = -1;
        while(idx2 < sz) {
            int idx1_nxt = (idx1 + 1) % sz;
            int idx2_nxt = (idx2 + 1) % sz;
            pll v1 = {P[st[idx1_nxt]].X - P[st[idx1]].X, P[st[idx1_nxt]].Y - P[st[idx1]].Y};
            pll v2 = {P[st[idx2_nxt]].X - P[st[idx2]].X, P[st[idx2_nxt]].Y - P[st[idx2]].Y};
            long long tmp = dist(P[st[idx1]], P[st[idx2]]);
            if(mx < tmp) {
                mx = tmp;
                ans1 = P[st[idx1]];
                ans2 = P[st[idx2]];
            }
            
            if(ccw(v1, v2) >= 0) ++idx2;
            else ++idx1;
        }
        
        cout << ans1.X << ' ' << ans1.Y << ' ' << ans2.X << ' ' << ans2.Y << '\n';
    }
    
    return 0;
}