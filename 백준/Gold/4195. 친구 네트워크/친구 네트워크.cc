#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
using namespace std;

int T, F;
string str1, str2;
int parent[200001], cnt[200001], urank[200001];
unordered_map<string, int> idx;
int idxCnt = 1;

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void Union(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    
    if(urank[a] == urank[b]) ++urank[a];
    if(urank[a] > urank[b]) parent[b] = a;
    else parent[a] = b;
    
    int sum = cnt[a] + cnt[b];
    cnt[a] = sum;
    cnt[b] = sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        idx.clear();
        memset(parent, 0, sizeof(parent));
        memset(cnt, 0, sizeof(cnt));
        memset(urank, 0, sizeof(urank));
        
        cin >> F;
        while(F--) {
            cin >> str1 >> str2;
            if(idx.find(str1) == idx.end()) {
                idx[str1] = idxCnt;
                parent[idxCnt] = idxCnt;
                cnt[idxCnt++] = 1;
            }
            
            if(idx.find(str2) == idx.end()) {
                idx[str2] = idxCnt;
                parent[idxCnt] = idxCnt;
                cnt[idxCnt++] = 1;
            }
            
            Union(idx[str1], idx[str2]);
            cout << cnt[find(idx[str1])] << '\n';
        }
    }
    
    return 0;
}