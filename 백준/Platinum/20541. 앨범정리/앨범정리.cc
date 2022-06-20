#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
class alb {
public:
    string album_name = "";
    set<string> photo;
    set<alb> sub_album;
    alb *parent = nullptr;
    alb(string s, alb *u) :album_name(s), parent(u) {}
    alb(string s) :album_name(s) {}
    bool operator<(const alb &a) const { return this->album_name < a.album_name; }
    bool operator==(const alb &a) const { return this->album_name == a.album_name; }
    inline int getAlbumCount() const { return sub_album.size(); }
    inline int getPhotoCount() const { return photo.size(); }
    void subAlbumCount(int &cnt) const {
        ++cnt;
        if (sub_album.empty()) return;
        for (auto &e : sub_album) {
            e.subAlbumCount(cnt);
        }
        return;
    }
    void subPhotoCount(int &cnt) const {
        cnt += this->getPhotoCount();
        if (sub_album.empty()) return;
        for (auto &e : sub_album) {
            e.subPhotoCount(cnt);
        }
        return;
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; string inst, arg;
    alb explorer("album", &explorer);
    alb *cur = &explorer;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> inst;
        if (inst == "mkalb") {
            cin >> arg;
            if (cur->sub_album.find(alb(arg)) != cur->sub_album.end())
                cout << "duplicated album name\n";
            else cur->sub_album.insert({ alb(arg, cur) });
        }
        else if (inst == "rmalb") {
            int del_album_cnt = 0, del_photo_cnt = 0;
            cin >> arg;
            if (arg == "-1" && !cur->sub_album.empty()) {
                cur->sub_album.begin()->subAlbumCount(del_album_cnt);
                cur->sub_album.begin()->subPhotoCount(del_photo_cnt);
                cur->sub_album.erase(cur->sub_album.begin());
            }
            else if (arg == "0" && !cur->sub_album.empty()) {
                for (auto &e : cur->sub_album) {
                    e.subAlbumCount(del_album_cnt);
                    e.subPhotoCount(del_photo_cnt);
                }
                cur->sub_album.clear();
            }
            else if (arg == "1" && !cur->sub_album.empty()) {
                prev(cur->sub_album.end())->subAlbumCount(del_album_cnt);
                prev(cur->sub_album.end())->subPhotoCount(del_photo_cnt);
                cur->sub_album.erase(prev(cur->sub_album.end()));
            }
            else {
                auto tar = cur->sub_album.find(alb(arg));
                if (tar != cur->sub_album.end()) {
                    tar->subAlbumCount(del_album_cnt);
                    tar->subPhotoCount(del_photo_cnt);
                    cur->sub_album.erase(tar);
                }
            }
            cout << del_album_cnt << " " << del_photo_cnt << "\n";
        }
        else if (inst == "insert") {
            cin >> arg;
            if (cur->photo.find(arg) != cur->photo.end()) cout << "duplicated photo name\n";
            else cur->photo.insert(arg);
        }
        else if (inst == "delete") {
            int del_photo_cnt = 0;
            cin >> arg;
            if (arg == "-1" && !cur->photo.empty()) {
                cur->photo.erase(cur->photo.begin());
                del_photo_cnt = 1;
            }
            else if (arg == "0" && !cur->photo.empty()) {
                del_photo_cnt = cur->photo.size();
                cur->photo.clear();
            }
            else if (arg == "1" && !cur->photo.empty()) {
                cur->photo.erase(prev(cur->photo.end()));
                del_photo_cnt = 1;
            }
            else {
                auto tar = cur->photo.find(arg);
                if (tar != cur->photo.end()) {
                    cur->photo.erase(tar);
                    del_photo_cnt = 1;
                }
            }
            cout << del_photo_cnt << "\n";
        }
        else if (inst == "ca") {
            cin >> arg;
            if (arg == "..") {
                cur = cur->parent;
            }
            else if (arg == "/") {
                cur = &explorer;
            }
            else {
                auto tar = cur->sub_album.find(alb(arg));
                if (tar != cur->sub_album.end()) {
                    cur = const_cast<alb *>(addressof(*tar));
                }
            }
            cout << cur->album_name << "\n";
        }
        else [[unlikely]] assert(0);
    }
    return 0;
}