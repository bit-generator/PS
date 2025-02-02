#include <iostream>
#include <deque>
using namespace std;

int N, M, onePos;
deque<int> arr;
int pushL1, pushL2, revL, revR;

bool isBackwardDir(int a, int b) {
    return a == b + 1 || (a == 1 && b == N);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> M;
        arr.push_back(M);
        if(M == 1) onePos = i;
    }
    
    int start = 0, mid = 1;
    while(!isBackwardDir(arr[start], arr[mid])) {
        start = (start + 1) % N;
        mid = (mid + 1) % N;
    }
    
    int last = mid + 1;
    int cnt = 0;
    while(isBackwardDir(arr[mid], arr[last]) && cnt != N) {
        mid = (mid + 1) % N;
        last = (last + 1) % N;
        ++cnt;
    }
    last = mid;
    mid = start;
    if(--start < 0) start = N - 1;
    
    if(cnt == N) {
        start = N - 1;
        last = start - 2;
    }
    else {
        while(isBackwardDir(arr[start], arr[mid])) {
            if(--mid < 0) mid = N - 1;
            --start;
        }
        
        start = mid;
    }
    
    do {
        arr.push_front(arr.back());
        arr.pop_back();
        start = (start + 1) % N;
        last = (last + 1) % N;
        onePos = (onePos + 1) % N;
        ++pushL2;
    } while(start > last || onePos == 0 || (start == 0 && last == onePos));
    
    revL = start + 1, revR = last + 1;
    if(onePos >= start && onePos <= last) {
        onePos = last - (onePos - start);
    }
    
    pushL1 = N - onePos;
    cout << pushL1 << '\n';
    cout << revL << ' ' << revR << '\n';
    cout << pushL2;
    return 0;
}