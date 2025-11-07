#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
using pll = pair<long long, long long>;

int N;
pll P[100000];
vector<int> st;

bool cmp1(const pll& p1, const pll& p2) {
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

long long ccw(const pll& p1, const pll& p2, const pll& p3) {
    pll v1 = {p2.first - p1.first, p2.second - p1.second};
    pll v2 = {p3.first - p1.first, p3.second - p1.second};
    return v1.first * v2.second - v1.second * v2.first;
}

inline long long pow(long long x) { return x * x; }

inline long long dist(const pll& p1, const pll& p2) {
    return pow(p2.first - p1.first) + pow(p2.second - p1.second);
}

bool cmp2(const pll& p1, const pll& p2) {
    long long tmp = ccw(P[0], p1, p2);
    if(tmp == 0) return dist(P[0], p1) < dist(P[0], p2);
    return tmp > 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> P[i].first >> P[i].second;
    sort(P, P + N, cmp1);
    sort(P + 1, P + N, cmp2);
    
    st.push_back(0);
    st.push_back(1);
    for(int i = 2; i < N; ++i) {
        while(st.size() >= 2) {
            int tmp1 = st[st.size() - 2];
            int tmp2 = st[st.size() - 1];
            if(ccw(P[tmp1], P[tmp2], P[i]) <= 0) st.pop_back();
            else break;
        }
        
        st.push_back(i);
    }
    
    cout << st.size();
    return 0;
}