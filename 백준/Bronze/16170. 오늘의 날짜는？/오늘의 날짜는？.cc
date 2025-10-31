#include <iostream>
#include <ctime>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    time_t timer;
    struct tm* t;
    timer = time(nullptr);
    t = localtime(&timer);
    
    cout << t->tm_year + 1900 << '\n';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mon + 1 << '\n';
    cout.width(2);
    cout.fill('0');
    cout << t->tm_mday;
    return 0;
}