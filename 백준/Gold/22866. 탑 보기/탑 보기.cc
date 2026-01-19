#include <iostream>
#include <stack>
using namespace std;

int N;
int building[100001];
stack<int> st;
int cnt[100001];
int closest[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> building[i];
    
    for(int i = 1; i <= N; ++i) {
        while(!st.empty() && building[st.top()] <= building[i]) {
            st.pop();
        }
        
        cnt[i] += st.size();
        if(!st.empty()) closest[i] = st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for(int i = N; i >= 1; --i) {
        while(!st.empty() && building[st.top()] <= building[i]) {
            st.pop();
        }
        
        cnt[i] += st.size();
        if(!st.empty()) {
            if(closest[i] == 0 || (st.top() - i < i - closest[i]))
                closest[i] = st.top();
        }
        st.push(i);
    }
    
    for(int i = 1; i <= N; ++i) {
        cout << cnt[i];
        if(cnt[i] != 0) cout << ' ' << closest[i];
        cout << '\n';
    }
    
    return 0;
}