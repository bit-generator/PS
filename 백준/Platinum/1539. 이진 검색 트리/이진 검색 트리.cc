#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#define LEFT    0
#define RIGHT    1
#define EMPTY    -1
using namespace std;

int N, num;
long long ans;
set<int> s;
int tree[250002][2];
int depth[250002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(tree, EMPTY, sizeof(int) * 250002 * 2);

    cin >> N;
    s.insert(250001);

    while (N--) {
        cin >> num;
        int parent = *(s.lower_bound(num));
        if (tree[parent][LEFT] == EMPTY) {
            tree[parent][LEFT] = num;
            depth[num] = depth[parent] + 1;
        }
        else {
            parent = tree[parent][LEFT];
            if (tree[parent][RIGHT] == EMPTY) {
                tree[parent][RIGHT] = num;
                depth[num] = depth[parent] + 1;
            }
            else {
                tree[tree[parent][RIGHT]][RIGHT] = num;
                depth[num] = depth[tree[parent][RIGHT]] + 1;
                tree[parent][RIGHT] = num;
            }
        }

        ans += depth[num];
        s.insert(num);
    }

    cout << ans;
    return 0;
}