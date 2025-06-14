#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
using namespace std;

int N;
string cmd, opt;

struct Album {
    string name;
    map<string, Album*> albums;
    set<string> photo;
    Album* prv;
    int albumCnt;
    int photoCnt;
} albumpool[100001];

Album* cur;
int albumCnt = 0;

Album* makeAlbum(const string& name) {
    albumpool[albumCnt].name = name;
    albumpool[albumCnt].prv = cur;

    Album* tmp = cur;
    while (tmp != nullptr) {
        ++(tmp->albumCnt);
        tmp = tmp->prv;
    }

    return &albumpool[albumCnt++];
}

void removeAlbum(const string& name, int& albumCnt, int& photoCnt) {
    albumCnt = cur->albums[name]->albumCnt + 1;
    photoCnt = cur->albums[name]->photoCnt;
    cur->albums.erase(name);

    Album* tmp = cur;
    while (tmp != nullptr) {
        tmp->albumCnt -= albumCnt;
        tmp->photoCnt -= photoCnt;
        tmp = tmp->prv;
    }
}

void removePhoto(const string& name, int& photoCnt) {
    photoCnt = 1;
    cur->photo.erase(name);

    Album* tmp = cur;
    while (tmp != nullptr) {
        --tmp->photoCnt;
        tmp = tmp->prv;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cur = makeAlbum("album");

    cin >> N;
    while (N--) {
        cin >> cmd >> opt;
        if (cmd == "mkalb") {
            if (cur->albums.find(opt) != cur->albums.end()) {
                cout << "duplicated album name\n";
            }
            else {
                cur->albums.emplace(opt, makeAlbum(opt));
            }
        }
        else if (cmd == "rmalb") {
            int erasedAlbum = 0, erasedPhoto = 0;

            if (!cur->albums.empty()) {
				if (opt == "-1") {
					removeAlbum(cur->albums.begin()->second->name, erasedAlbum, erasedPhoto);
				}
				else if (opt == "0") {
					erasedAlbum = cur->albumCnt;
					erasedPhoto = cur->photoCnt - cur->photo.size();
					cur->albums.clear();

                    Album* tmp = cur;
                    while (tmp != nullptr) {
                        tmp->albumCnt -= erasedAlbum;
                        tmp->photoCnt -= erasedPhoto;
                        tmp = tmp->prv;
                    }
				}
				else if (opt == "1") {
					removeAlbum((--cur->albums.end())->second->name, erasedAlbum, erasedPhoto);
				}
				else {
					if(cur->albums.find(opt) != cur->albums.end())
                        removeAlbum(opt, erasedAlbum, erasedPhoto);
				}
            }

            cout << erasedAlbum << ' ' << erasedPhoto << '\n';
        }
        else if (cmd == "insert") {
            if (cur->photo.find(opt) != cur->photo.end()) {
                cout << "duplicated photo name\n";
            }
            else {
                cur->photo.insert(opt);
                Album* tmp = cur;
                while (tmp != nullptr) {
                    ++tmp->photoCnt;
                    tmp = tmp->prv;
                }
            }
        }
        else if (cmd == "delete") {
            int erasedPhoto = 0;

            if (!cur->photo.empty()) {
				if (opt == "-1") {
					removePhoto(*(cur->photo.begin()), erasedPhoto);
				}
				else if (opt == "0") {
					erasedPhoto = cur->photo.size();
					cur->photo.clear();

					Album* tmp = cur;
					while (tmp != nullptr) {
						tmp->photoCnt -= erasedPhoto;
						tmp = tmp->prv;
					}
				}
				else if (opt == "1") {
					removePhoto(*(--cur->photo.end()), erasedPhoto);
				}
				else {
					if(cur->photo.find(opt) != cur->photo.end())
						removePhoto(opt, erasedPhoto);
				}
            }
            
            cout << erasedPhoto << '\n';
        }
        else {
            if (opt == "/") {
                cur = &albumpool[0];
            }
            else if (opt == "..") {
                if (cur->prv != nullptr) cur = cur->prv;
            }
            else {
                if (cur->albums.find(opt) != cur->albums.end()) {
                    cur = cur->albums[opt];
                }
            }

            cout << cur->name << '\n';
        }
    }

    return 0;
}