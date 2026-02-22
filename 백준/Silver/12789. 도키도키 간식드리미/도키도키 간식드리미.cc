#include <iostream>
#include <stack>
using namespace std;

int N, M, cnt = 1;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> M;
        if(cnt == M) ++cnt;
        else {
            while(!st.empty() && st.top() == cnt) {
                ++cnt;
                st.pop();
            }
            
            st.push(M);
        }
    }
    
    while(!st.empty()) {
        int tmp = st.top();
        st.pop();
        
        if(tmp == cnt) ++cnt;
        else {
            cout << "Sad";
            return 0;
        }
    }
    
    cout << "Nice";
    return 0;
}