#include <iostream>
#include <algorithm>
using namespace std;

int n, m, a, b, c;
int city[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        cin >> a >> b >> c;
        if (city[a][b] == 0) city[a][b] = c;
        else city[a][b] = min(city[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (j == k) continue;
                if (city[j][i] != 0 && city[i][k] != 0) {
                    if (city[j][k] == 0) city[j][k] = city[j][i] + city[i][k];
                    else city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
                }
                    
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << city[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}