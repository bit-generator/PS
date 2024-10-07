#include <iostream>
#include <vector>
using namespace std;

int N, M, cnt = 1, maxlv, ans, sum;
int tree[10001][2];
int level[10001];
vector<int> order[10001];

void inorder(int x) {
    if(tree[x][0] != -1) {
        level[tree[x][0]] = level[x] + 1;
        inorder(tree[x][0]);
    }
    order[level[x]].push_back(cnt++);
    if(tree[x][1] != -1) {
        level[tree[x][1]] = level[x] + 1;
        inorder(tree[x][1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    sum = (N * (N + 1)) / 2;
    for(int i = 1; i <= N; i++) {
        cin >> M;
        cin >> tree[M][0] >> tree[M][1];
        if(tree[M][0] != -1) sum -= tree[M][0];
        if(tree[M][1] != -1) sum -= tree[M][1];
    }
    
    level[sum] = 1;
    inorder(sum);
    
    for(int i = 1; order[i].size() != 0; i++) {
        int width = *(--order[i].end()) - *order[i].begin() + 1;
        if(ans < width) {
            ans = width;
            maxlv = i;
        }
    }
    
    cout << maxlv << ' ' << ans;   
    return 0;
}