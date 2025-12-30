#include <iostream>
#include <stack>
using namespace std;

int n, x, y, ans;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    while(n--) {
        cin >> x >> y;
        
        while(!st.empty() && st.top() > y) {
            st.pop();
            ++ans;
        }
        
        if(y != 0 && (st.empty() || st.top() < y)) {
            st.push(y);
        }
    }
    
    while(!st.empty()) {
        st.pop();
        ++ans;
    }
    
    cout << ans;
    return 0;
}