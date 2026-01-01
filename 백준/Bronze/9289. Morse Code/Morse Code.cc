#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, char> morse = {
    {".-", 'A'}, {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'}, {".", 'E'},
    {"..-.", 'F'}, {"--.", 'G'}, {"....", 'H'}, {"..", 'I'}, {".---", 'J'},
    {"-.-", 'K'}, {".-..", 'L'}, {"--", 'M'}, {"-.", 'N'}, {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'}, {"...", 'S'}, {"-", 'T'},
    {"..-", 'U'}, {"...-", 'V'}, {".--", 'W'}, {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'}
};
string str[5];
int T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    for(int tc = 1; tc <= T; ++tc) {
        for(int i = 0; i < 5; ++i) cin >> str[i];
        cout << "Case " << tc << ": ";
        for(int i = 0; i < 5; ++i) cout << morse[str[i]];
        cout << '\n';
    }
    
    return 0;
}