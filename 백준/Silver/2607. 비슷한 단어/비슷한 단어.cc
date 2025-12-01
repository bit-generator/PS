#include <iostream>
#include <string>
using namespace std;

int N, ans;
string str1, str2;
char cnt[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> str1;
    for (char c : str1) ++cnt[c - 'A'];

    while (--N) {
        cin >> str2;
        int diff = str1.length() - str2.length();
        if (diff >= 2 || diff <= -2) continue;

        char tmp[26] = {0};
        int err = 0;
        for (char c : str2) {
            if (++tmp[c - 'A'] > cnt[c - 'A']) ++err;
        }

        if (diff == 1 && err == 0) ++ans;
        if (diff == 0 && err <= 1) ++ans;
        if (diff == -1 && err == 1) ++ans;
    }

    cout << ans;
    return 0;
}