#include <iostream>
#include <deque>
using namespace std;

int N;
int arr[1001];
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> arr[i];
        dq.push_back(i);
    }
    
    int idx = dq.front();
    dq.pop_front();
    cout << idx << ' ';
    
    while(!dq.empty()) {
        int cnt = arr[idx];
        if(cnt > 0) {
            for(int i = 0; i < cnt - 1; ++i) {
                int tmp = dq.front();
                dq.push_back(tmp);
                dq.pop_front();
            }
        }
        else {
            for(int i = 0; i > cnt; --i) {
                int tmp = dq.back();
                dq.push_front(tmp);
                dq.pop_back();
            }
        }
        
        idx = dq.front();
        dq.pop_front();
        cout << idx << ' ';
    }
    
    return 0;
}