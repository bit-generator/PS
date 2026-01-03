#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str, target, ans;
vector<char> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str >> target;
    for (int i = 0; i < str.length(); ++i) {
        st.push_back(str[i]);
        if (st.size() >= target.size() && str[i] == target[target.size() - 1]) {
            string tmp(st.end() - target.length(), st.end());
            if (tmp == target) {
                for (int j = 0; j < target.size(); ++j) st.pop_back();
            }
        }
    }

    ans = string(st.begin(), st.end());
    if (ans == "") cout << "FRULA";
    else cout << ans;
    return 0;
}