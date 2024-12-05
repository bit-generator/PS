#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int N, sum;
int arr[500000];
int cnt[8001];
deque<int> dq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        sum += arr[i];
        ++cnt[arr[i] + 4000];
    }

    sort(arr, arr + N);
    double avg = (double)sum / N;
    cout << (int)(avg + (avg >= 0 ? 0.5 : -0.5)) << '\n';
    cout << arr[N / 2] << '\n';

    int maxCnt = 0;
    for (int i = arr[N - 1]; i >= arr[0]; --i) {
        if (cnt[i + 4000] > maxCnt) {
            maxCnt = cnt[i + 4000];
            dq.clear();
            dq.push_back(i);
        }
        else if (cnt[i + 4000] == maxCnt) {
            dq.push_back(i);
            if (dq.size() > 2) dq.pop_front();
        }
    }

    cout << dq.front() << '\n';
    cout << arr[N - 1] - arr[0];

    return 0;
}