#include <iostream>
#include <algorithm>
using namespace std;

int n;
int clk[2][200000];
int space[2][400000];
int F[200000];

void getFailure() {
    int j = 0;
    for (int i = 1; i < n; ++i) {
        while (j > 0 && space[1][i] != space[1][j]) j = F[j - 1];
        if (space[1][i] == space[1][j]) F[i] = ++j;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) cin >> clk[i][j];
    }

    sort(clk[0], clk[0] + n);
    sort(clk[1], clk[1] + n);

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            space[i][j] = clk[i][j + 1] - clk[i][j];
        }

        space[i][n - 1] = clk[i][0] + 360000 - clk[i][n - 1];
        
        if(i == 0) {
            for(int j = n; j < n * 2; ++j) {
                space[i][j] = space[i][j - n];
            }
        }
    }

    getFailure();

    int j = 0;
    for (int i = 0; i < 2 * n; ++i) {
        while (j > 0 && space[0][i] != space[1][j]) j = F[j - 1];
        if (space[0][i] == space[1][j]) ++j;
        if(j == n) {
            cout << "possible";
            return 0;
        }
    }

    cout << "impossible";
    return 0;
}