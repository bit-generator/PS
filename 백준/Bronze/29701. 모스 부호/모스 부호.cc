#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N;
string str;
unordered_map<string, char> mors;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    mors[".-"] = 'A', mors["-..."] = 'B', mors["-.-."] = 'C', mors["-.."] = 'D',
    mors["."] = 'E', mors["..-."] = 'F', mors["--."] = 'G', mors["...."] = 'H',
    mors[".."] = 'I', mors[".---"] = 'J', mors["-.-"] = 'K', mors[".-.."] = 'L',
    mors["--"] = 'M', mors["-."] = 'N', mors["---"] = 'O', mors[".--."] = 'P',
    mors["--.-"] = 'Q', mors[".-."] = 'R', mors["..."] = 'S', mors["-"] = 'T',
    mors["..-"] = 'U', mors["...-"] = 'V', mors[".--"] = 'W', mors["-..-"] = 'X',
    mors["-.--"] = 'Y', mors["--.."] = 'Z',
    mors[".----"] = '1', mors["..---"] = '2', mors["...--"] = '3', mors["....-"] = '4',
    mors["....."] = '5', mors["-...."] = '6', mors["--..."] = '7', mors["---.."] = '8',
    mors["----."] = '9', mors["-----"] = '0', mors["--..--"] = ',', mors[".-.-.-"] = '.',
    mors["..--.."] = '?', mors["---..."] = ':', mors["-....-"] = '-', mors[".--.-."] = '@';
    
    cin >> N;
    while(N--) {
        cin >> str;
        cout << mors[str];
    }
    
    return 0;
}