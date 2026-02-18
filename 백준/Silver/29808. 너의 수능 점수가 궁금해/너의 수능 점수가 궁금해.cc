#include <iostream>
#include <set>
#include <utility>
using namespace std;

int S;
set<pair<int, int>> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> S;
    if(S % 4763) {
        cout << 0;
        return 0;
    }
    
    S /= 4763;
    for(int i = 0; i <= S && i / 108 <= 200; i += 108) {
        int diff = S - i;
        if(diff % 212 == 0 && diff / 212 <= 200) 
            ans.emplace(i / 108, diff / 212);
        if(diff % 305 == 0 && diff / 305 <= 200)
            ans.emplace(i / 108, diff / 305);
    }
    
    for(int i = 0; i <= S && i / 508 <= 200; i += 508) {
        int diff = S - i;
        if(diff % 212 == 0 && diff / 212 <= 200) 
            ans.emplace(i / 508, diff / 212);
        if(diff % 305 == 0 && diff / 305 <= 200) 
            ans.emplace(i / 508, diff / 305);
    }
    
    cout << ans.size() << '\n';
    for(const auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }
    
    return 0;
}