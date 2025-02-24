#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n, r;
char cmd;
string station, feature;
unordered_map<string, int> stnmask;
unordered_map<string, int> featmap;
unordered_map<int, int> featcount;
int featCnt = 0;

int makeMask(string& feat, int mode = 0) {
    int masked = 0;
    int pos;
    int prev = 0;
    while ((pos = feat.find(',', prev)) != -1) {
        string parsed = feat.substr(prev, pos - prev);
        if (featmap.find(parsed) == featmap.end()) {
            if (!mode) featmap[parsed] = featCnt++;
            else return -1;
        }

        masked |= (1 << featmap[parsed]);
        prev = pos + 1;
    }

    string parsed = feat.substr(prev);
    if (featmap.find(parsed) == featmap.end()) {
        featmap[parsed] = featCnt++;
    }

    masked |= (1 << featmap[parsed]);
    return masked;
}

void adjust(int mask, int val, int st = 0, int key = 0) {
    for (int i = st; i < 9; ++i) {
        if (mask & (1 << i)) {
            key |= (1 << i);
            featcount[key] += val;
            adjust(mask, val, i + 1, key);
            key &= ~(1 << i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--) {
        cin >> station;
        stnmask[station] = 0;
    }

    cin >> r;
    while (r--) {
        cin >> cmd;
        if (cmd == 'U') {
            cin >> station >> feature;
            int mask = makeMask(feature);

            if (stnmask.find(station) != stnmask.end()) {
                adjust(stnmask[station], -1);
            }

            stnmask[station] = mask;
            adjust(stnmask[station], 1);
        }
        else {
            cin >> feature;
            int mask = makeMask(feature, 1);
            if (mask == -1) cout << 0 << '\n';
            else cout << featcount[mask] << '\n';
        }
    }

    return 0;
}