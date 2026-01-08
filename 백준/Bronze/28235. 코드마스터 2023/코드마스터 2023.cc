#include <iostream>
#include <string>
using namespace std;

string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    if(str == "SONGDO") cout << "HIGHSCHOOL";
    if(str == "CODE") cout << "MASTER";
    if(str == "2023") cout << "0611";
    if(str == "ALGORITHM") cout << "CONTEST";
    
    return 0;
}