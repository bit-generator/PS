#include <iostream>
#include <vector>
#define MOD    1000
using namespace std;
using vint = vector<vector<int>>;

int N;
long long B;
vint mat, ans;

vint times(vint& a, vint& b) {
    vint ret(N, vector<int>(N, 0));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                ret[i][j] = (ret[i][j] + (a[i][k] * b[k][j]) % MOD) % MOD;
            }
        }
    }

    return ret;
}

vint pow(long long n) {
    if (n == 1) return mat;

    vint tmp = pow(n / 2);
    vint ret = times(tmp, tmp);

    if (n % 2) {
        return times(ret, mat);
    }
    else {
        return ret;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> B;
    mat.resize(N);

    for (int i = 0; i < N; ++i) {
        mat[i].resize(N);

        for (int j = 0; j < N; ++j) {
            cin >> mat[i][j];
            mat[i][j] %= MOD;
        }
    }

    ans = pow(B);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}