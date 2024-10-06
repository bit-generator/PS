#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int t, sm, sc, si, ptr, inputIdx, loopCnt, minloopIdx, maxloopIdx;
bool looped;
string code, inputStr;
stack<int> st;
int bracketIdx[4096];
unsigned char memory[100000];
const int UCHAR_SIZE = 1 << 8;

void init() {
    ptr = 0;
    inputIdx = 0;
    loopCnt = 0;
    minloopIdx = 4096;
    maxloopIdx = 0;
    looped = false;
    memset(memory, 0, sizeof(unsigned char) * sm);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> t;
    while(t--) {
        cin >> sm >> sc >> si;
        cin >> code >> inputStr;
        
        init();
        
        for(int i = 0; i < sc; i++) {
            if(code[i] == '[') {
                st.push(i);
            }
            else if(code[i] == ']') {
                bracketIdx[i] = st.top();
                bracketIdx[st.top()] = i;
                st.pop();
            }
        }
        
        for(int i = 0; i < sc; i++) {
            if(loopCnt >= 50'000'000) {
                minloopIdx = min(minloopIdx, i - 1);
                maxloopIdx = max(maxloopIdx, i);
            }
            
            if(loopCnt == 100'000'000) {
                looped = true;
                break;
            }
            
            if(code[i] == '-') {
                memory[ptr] = (memory[ptr] + UCHAR_SIZE - 1) % UCHAR_SIZE;
            }
            else if(code[i] == '+') {
                memory[ptr] = (memory[ptr] + 1) % UCHAR_SIZE;
            }
            else if(code[i] == '<') {
                ptr = (ptr + sm - 1) % sm;
            }
            else if(code[i] == '>') {
                ptr = (ptr + 1) % sm;
            }
            else if(code[i] == '[') {
                if(memory[ptr] == 0) {
                    i = bracketIdx[i];
                }
            }
            else if(code[i] == ']') {
                if(memory[ptr] != 0) {
                    i = bracketIdx[i];
                }
            }
            else if(code[i] == ',') {
                if(inputIdx == inputStr.length()) {
                    memory[ptr] = 255;
                }
                else memory[ptr] = inputStr[inputIdx++];
            }
            
            loopCnt++;
        }
        
        if(looped) cout << "Loops " << minloopIdx << ' ' << maxloopIdx << '\n';
        else cout << "Terminates\n";
    }
    
    return 0;
}