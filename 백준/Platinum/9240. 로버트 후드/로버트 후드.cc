#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#define X    first
#define Y    second
using namespace std;
using pll = pair<long long, long long>;

int C;
pll P[100000];
vector<int> st;

bool yfirst(const pll& a, const pll& b) {
    if (a.Y == b.Y) return a.X < b.X;
    return a.Y < b.Y;
}

long long ccw(const pll& v1, const pll& v2) {
    return v1.X * v2.Y - v2.X * v1.Y;
}

long long ccw(const pll& p1, const pll& p2, const pll& p3) {
    pll v1 = { p2.X - p1.X, p2.Y - p1.Y };
    pll v2 = { p3.X - p1.X, p3.Y - p1.Y };
    return v1.X * v2.Y - v2.X * v1.Y;
}

inline long long pow(int x) { return x * x; }

inline long long dist(const pll& p1, const pll& p2) {
    return pow(p2.X - p1.X) + pow(p2.Y - p1.Y);
}

bool ccwfirst(const pll& a, const pll& b) {
    int tmp = ccw(P[0], a, b);
    if (tmp == 0) return dist(P[0], a) < dist(P[0], b);
    return tmp > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> C;
    for (int i = 0; i < C; ++i) {
        cin >> P[i].X >> P[i].Y;
    }

    sort(P, P + C, yfirst);
    sort(P + 1, P + C, ccwfirst);
    st.push_back(0);
    st.push_back(1);

    for (int i = 2; i < C; ++i) {
        while (st.size() >= 2) {
            int idx1 = st[st.size() - 2];
            int idx2 = st[st.size() - 1];
            if (ccw(P[idx1], P[idx2], P[i]) <= 0) st.pop_back();
            else break;
        }

        st.push_back(i);
    }

    int pidx1 = 0, pidx2 = 1;
    int sz = st.size();
    long long ans = 0;

    while (pidx2 != st[0]) {
        int pidx1_nxt = (pidx1 + 1) % sz;
        int pidx2_nxt = (pidx2 + 1) % sz;
        pll v1 = { P[st[pidx1_nxt]].X - P[st[pidx1]].X, P[st[pidx1_nxt]].Y - P[st[pidx1]].Y };
        pll v2 = { P[st[pidx2_nxt]].X - P[st[pidx2]].X, P[st[pidx2_nxt]].Y - P[st[pidx2]].Y };
        ans = max(ans, dist(P[st[pidx1]], P[st[pidx2]]));

        if (ccw(v1, v2) >= 0) {
            pidx2 = (pidx2 + 1) % sz;
        }
        else {
            pidx1 = (pidx1 + 1) % sz;
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << sqrt((double)ans);
    return 0;
}