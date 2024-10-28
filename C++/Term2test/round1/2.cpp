#include <iostream>
#include <string>
using namespace std;

class Film {
  public:
    string title;
    string director;
    int time;
    int quality;
    virtual void input() { in1(); }
    virtual void output() { out1(); }
    void out1() {
        cout << "Title: " << title << "\nDirector: " << director
             << "\nTime: " << time << " mins\nQuality: ";
        for (int q = 0; q < quality; q++)
            cout << '*';
        cout << endl;
    }
    void in1() {
        cout << "Input class name:\nInput title:\nInput director:\nInput "
                "time:\nInput quality:\n";

        string title, director;
        int time, quality;

        getline(cin, title);
        title = title;
        getline(cin, director);
        director = director;
        cin >> time;
        time = time;
        cin >> quality;
        quality = quality;
    }
};
class DirectorCut : public Film {
  public:
    int rev_time;
    string changes;

    virtual void output() {
        out1();
        out2();
    }
    virtual void input() {
        in1();
        in2();
    }
    void out2() {
        cout << "Revised time: " << rev_time << " mins\nChanges: " << changes
             << endl;
    }
    void in2() {
        cout << "Input rev_time:\nInput changes:\n";
        string changes;
        int rev_time;

        cin >> rev_time;
        time = rev_time;
        cin.ignore();
        getline(cin, changes);
        changes = changes;
    }
};
class ForeignFilm : public Film {
  public:
    string language;
    virtual void output() {
        out1();
        out2();
    }
    virtual void input() {
        in1();
        in2();
    }
    void out2() { cout << "Language: " << language << endl; }
    void in2() {
        cout << "Input language:\n";
        string language;
        getline(cin, language);
        language = language;
    }
};
Film *read_input(string class_name) {
    Film *res;
    if (class_name == "Film") {
        res = new Film;
    } else if (class_name == "DirectorCut") {
        res = new DirectorCut;
    } else {
        res = new ForeignFilm;
    }
    res->input();
    return res;
}
int main() {
    int n = 5;
    Film *films[n];
    for (int i = 0; i < n; i++) {
        cout << "Input class name:" << endl;
        string class_name;
        cin >> class_name;
        cin.ignore(); // 可以去除输入流中的换行符
        films[i] = read_input(class_name);
        cout << class_name << "--" << endl;
        films[i]->output();
        cout << endl;
    }
}