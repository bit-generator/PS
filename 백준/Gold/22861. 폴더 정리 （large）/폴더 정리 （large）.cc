#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Folder {
    string name;
    unordered_set<string> folders;
    unordered_set<string> files;
    int fileCnt;
} pool[1005];
int poolCnt;

int N, M, C, K, Q;
string P, F, A, B;
Folder* mainDir;
unordered_map<string, Folder*> folderIdx;

Folder* makeDir(const string& name) {
    pool[poolCnt].name = name;
    return &pool[poolCnt++];
}

void moveDir(Folder* src, Folder* dst) {
    dst->folders.insert(src->folders.begin(), src->folders.end());
    dst->files.insert(src->files.begin(), src->files.end());
    
    src->folders.clear();
    src->files.clear();
}

void dfs(Folder* cur) {
    cur->fileCnt = cur->files.size();
    
    for(auto it = cur->folders.begin(); it != cur->folders.end(); ++it) {
        if(folderIdx.find(*it) == folderIdx.end()) continue;
        dfs(folderIdx[*it]);
        cur->files.insert(folderIdx[*it]->files.begin(), folderIdx[*it]->files.end());
        cur->fileCnt += folderIdx[*it]->fileCnt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    folderIdx.emplace("main", makeDir("main"));
    cin >> N >> M;
    
    for(int i = 0; i < N + M; ++i) {
        cin >> P >> F >> C;
        if(folderIdx.find(P) == folderIdx.end()) {
                folderIdx.emplace(P, makeDir(P));
            }
        
        if(C) {
            if(folderIdx.find(F) == folderIdx.end()) {
                folderIdx.emplace(F, makeDir(F));
            }
            
            folderIdx[P]->folders.insert(F);
        }
        else {
            folderIdx[P]->files.insert(F);
        }
    }
    
    cin >> K;
    while(K--) {
        cin >> A >> B;
        int idxA = A.length() - 1;
        int idxB = B.length() - 1;
        while(idxA >= 0 && A[idxA] != '/') --idxA;
        while(idxB >= 0 && B[idxB] != '/') --idxB;
        
        string dirA = A.substr(idxA + 1);
        string dirB = B.substr(idxB + 1);
        moveDir(folderIdx[dirA], folderIdx[dirB]);
        folderIdx.erase(dirA);
    }
    
    dfs(&pool[0]);
    
    cin >> Q;
    while(Q--) {
        cin >> A;
        int idxA = A.length() - 1;
        while(idxA >= 0 && A[idxA] != '/') --idxA;
        string dirA = A.substr(idxA + 1);
        cout << folderIdx[dirA]->files.size() << ' ' << folderIdx[dirA]->fileCnt << '\n';
    }
    
    return 0;
}