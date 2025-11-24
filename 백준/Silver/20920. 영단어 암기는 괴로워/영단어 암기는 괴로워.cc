#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, M;
string str;
unordered_map<string, int> um;
vector<pair<string, int>> v;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
    if(a.second == b.second) {
        if(a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        
        return a.first.length() > b.first.length();
    }
    
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(N--) {
        cin >> str;
        if(str.length() >= M) ++um[str];
    }
    
    for(auto it = um.begin(); it != um.end(); ++it) {
        v.push_back(*it);
    }
    
    sort(v.begin(), v.end(), compare);
    for(const auto& p : v) {
        cout << p.first << '\n';
    }
    
    return 0;
}