#include <iostream>
#include <deque>
using namespace std;

int N, cmd, num;
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> cmd;
        if(cmd == 1) {
            cin >> num;
            dq.push_front(num);
        }
        else if(cmd == 2) {
            cin >> num;
            dq.push_back(num);
        }
        else if(cmd == 3) {
            if(dq.empty()) {
                cout << -1 << '\n';
                continue;
            }
            
            cout << dq.front() << '\n';
            dq.pop_front();
        }
        else if(cmd == 4) {
            if(dq.empty()) {
                cout << -1 << '\n';
                continue;
            }
            
            cout << dq.back() << '\n';
            dq.pop_back();
        }
        else if(cmd == 5) {
            cout << dq.size() << '\n';
        }
        else if(cmd == 6) {
            cout << (int)dq.empty() << '\n';
        }
        else if(cmd == 7) {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
    
    return 0;
}