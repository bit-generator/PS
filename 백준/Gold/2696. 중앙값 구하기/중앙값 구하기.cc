#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, M, N, mid;
priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<>> minpq;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        cin >> M >> mid;
        ans.clear();
        while(!minpq.empty()) minpq.pop();
        while(!maxpq.empty()) maxpq.pop();
        ans.push_back(mid);
        M /= 2;
        
        while(M--) {
            for(int i = 0; i < 2; ++i) {
                cin >> N;
                if(N < mid) maxpq.push(N);
                else minpq.push(N);    
            }
            
            while(maxpq.size() < minpq.size()) {
                maxpq.push(mid);
                mid = minpq.top();
                minpq.pop();
            }
            
            while(maxpq.size() > minpq.size()) {
                minpq.push(mid);
                mid = maxpq.top();
                maxpq.pop();
            }
            
            ans.push_back(mid);
        }
        
        cout << ans.size();
        for(int i = 0; i < ans.size(); ++i) {
            if(i % 10 == 0) cout << '\n';
            cout << ans[i] << ' ';  
        }
        cout << '\n';
    }
    
    return 0;
}