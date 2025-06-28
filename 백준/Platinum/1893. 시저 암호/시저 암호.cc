#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int N;
string A, W, S;
int F[50001];
int nxtIdx[128];
int cnt[62];
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    while (N--) {
        cin >> A >> W >> S;

        for (int i = 0; i < A.length(); ++i) {
            nxtIdx[A[i]] = (i + 1) % A.length();
        }
        memset(F, 0, sizeof(F));
        memset(cnt, 0, sizeof(cnt));
        ans.clear();

        int j = 0;
        for (int i = 1; i < W.length(); ++i) {
            while (j > 0 && W[i] != W[j]) j = F[j - 1];
            if (W[i] == W[j]) F[i] = ++j;
        }

        for(int i = 0; i < A.length(); ++i) {
            if(i > 0) {
                for(j = 0; j < W.length(); ++j) {
                    W[j] = A[nxtIdx[W[j]]];
                }
            }
            
            int idx = 0;
            for(j = 0; j < S.length(); ++j) {
                while(idx > 0 && S[j] != W[idx]) idx = F[idx - 1];
                if(S[j] == W[idx]) ++idx;
                if(idx == W.length()) {
                    ++cnt[i];
                    idx = F[idx - 1];
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