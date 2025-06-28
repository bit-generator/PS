#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N;
string A, W, S;
int F[50001];
int idx[62];
int idxmap[128];
int cnt[62];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while (N--) {
        cin >> A >> W >> S;

        for (int i = 0; i < A.length(); ++i) {
            idxmap[A[i]] = i;
        }
        memset(F, 0, sizeof(F));
        memset(idx, 0, sizeof(idx));
        memset(cnt, 0, sizeof(cnt));
        ans.clear();

        int j = 0;
        for (int i = 1; i < W.length(); ++i) {
            while (j > 0 && W[i] != W[j]) j = F[j - 1];
            if (W[i] == W[j]) F[i] = ++j;
        }

        for (int i = 0; i < S.length(); ++i) {
            for (j = 0; j < A.length(); ++j) {
                int& cur = idx[j];
                char cmp = A[(idxmap[W[cur]] + j) % A.length()];
                while (cur > 0 && S[i] != cmp) {
                    cur = F[cur - 1];
					cmp = A[(idxmap[W[cur]] + j) % A.length()];
                }

                if (S[i] == cmp) ++cur;
                if (cur == W.length()) {
                    ++cnt[j];
                    cur = F[cur - 1];
                }
            }
        }

        for (int i = 0; i < A.length(); ++i) {
            if (cnt[i] == 1) ans.push_back(i);
        }

        if (ans.size() == 0) cout << "no solution\n";
        else if (ans.size() == 1) {
            cout << "unique: " << ans[0] << '\n';
        }
        else {
            cout << "ambiguous: ";
            for (int n : ans) cout << n << ' ';
            cout << '\n';
        }
    }

    return 0;
}