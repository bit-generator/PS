#include <iostream>
using namespace std;

int n;
int inorder[100000], postorder[100000];
int inIdx[100001];

void solve(int start, int last, int offset) {
    int root = postorder[last - offset];
    cout << root << ' ';
    if(start <= inIdx[root] - 1) solve(start, inIdx[root] - 1, offset);
    if(inIdx[root] + 1 <= last) solve(inIdx[root] + 1, last, offset + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> inorder[i];
        inIdx[inorder[i]] = i;
    }
    
    for(int i = 0; i < n; ++i) cin >> postorder[i];
    
    solve(0, n - 1, 0);
    return 0;
}