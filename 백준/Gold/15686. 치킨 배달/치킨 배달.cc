#include <bits/stdc++.h>
#define X    first
#define Y    second
using namespace std;
using Pair = pair<int, int>;

int n, m;
vector<Pair> house;
vector<Pair> chicken;
vector<Pair> remains;
int ans = 10000;

void getDistance() {
    int chicDist = 0;
    for(int i = 0; i < house.size(); i++) {
        int temp = 10000;
        for(int j = 0; j < remains.size(); j++) {
            int dist = abs(house[i].X - remains[j].X) + abs(house[i].Y - remains[j].Y);
            temp = min(temp, dist);
        }
        
        chicDist += temp;
    }
    
    ans = min(chicDist, ans);
}

void func(int num) {
    if(remains.size() == m) {
        getDistance();
        return;
    }
    
    for(int i = num; i < chicken.size(); i++) {
        remains.push_back(chicken[i]);
        func(i + 1);
        remains.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    int num;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> num;
            if(num == 1) {
                house.push_back({i, j});
            }
            else if(num == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    
    func(0);
    cout << ans;
    return 0;
}