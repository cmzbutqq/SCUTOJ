#include <iostream>
#include <string>
using namespace std;

class Film {
  public:
    string title;
    string director;
    int time;
    int quality;

    virtual void output() { out1(); }
    void out1() {
        cout << "Title: " << title << "\nDirector: " << director
             << "\nTime: " << time << " mins\nQuality: ";
        for (int q = 0; q < quality; q++)
            cout << '*';
        cout << endl;
    }
    void store_title(auto arg) { title = arg; }
    void store_director(auto arg) { director = arg; }
    void store_time(auto arg) { time = arg; }
    void store_quality(auto arg) { quality = arg; }
};
class DirectorCut : public Film {
  public:
    int rev_time;
    string changes;

    virtual void output() {
        out1();
        out2();
    }
    void out2() {
        cout << "Revised time: " << rev_time << " mins\nChanges: " << changes
             << endl;
    }
    void store_rev_time(auto arg) { rev_time = arg; }
    void store_changes(auto arg) { changes = arg; }
};
class ForeignFilm : public Film {
  public:
    string language;
    virtual void output() {
        out1();
        out2();
    }
    void out2() { cout << "Language: " << language << endl; }
    void store_language(auto arg) { language = arg; }
};

int main() {

    string title, director, changes, language;
    int time, quality, rev_time;
    Film f;
    getline(cin, title);
    f.store_title(title);
    getline(cin, director);
    f.store_director(director);
    cin >> time;
    f.store_time(time);
    cin >> quality;
    f.store_quality(quality);
    cout << "Film--" << endl;
    f.output();
    cout << endl;
    cin.ignore();

    DirectorCut d;
    getline(cin, title);
    d.store_title(title);
    getline(cin, director);
    d.store_director(director);
    cin >> time;
    d.store_time(time);
    cin >> quality;
    d.store_quality(quality);
    cin >> rev_time;
    d.store_rev_time(rev_time); // 修订时间
    cin.ignore();
    getline(cin, changes);
    d.store_changes(changes); // 影片变更内容
    cout << "DirectorCut--" << endl;
    d.output();
    cout << endl;

    ForeignFilm ff;
    getline(cin, title);
    ff.store_title(title);
    getline(cin, director);
    ff.store_director(director);
    cin >> time;
    ff.store_time(time);
    cin >> quality;
    ff.store_quality(quality);
    cin.ignore();
    getline(cin, language);
    ff.store_language(language);
    cout << "ForeignFilm--" << endl;
    ff.output();
    cout << endl;

    return 0;
}