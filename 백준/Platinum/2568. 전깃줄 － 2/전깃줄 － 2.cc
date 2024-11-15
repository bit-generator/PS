#include <iostream>
#include <vector>
#include <utility>
#include <stack>
#include <algorithm>
using namespace std;

int N, A, B;
pair<int, int> arr[100000];
int idx[500001];
vector<int> v;
stack<int> st;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A >> B;
        arr[i] = { A, B };
    }
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        auto it = lower_bound(v.begin(), v.end(), arr[i].second);
        if (it == v.end()) {
            v.push_back(arr[i].second);
            idx[i] = v.size() - 1;
        }
        else {
            *it = arr[i].second;
            idx[i] = it - v.begin();
        }
    }
        

    int sz = v.size() - 1;
    for (int i = N - 1; i >= 0; i--) {
        if (idx[i] == sz) {
            --sz;
        }
        else {
            st.push(arr[i].first);
        }
    }

    cout << st.size() << '\n';
    while (!st.empty()) {
        cout << st.top() << '\n';
        st.pop();
    }
    return 0;
}