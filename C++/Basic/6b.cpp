#include <iostream>
using namespace std;

class Box {
  private:
    int length, width, height;

  public:
    Box(int l, int w, int h) : length(l), width(w), height(h) { volume(); }
    void setBox(int l, int w, int h) {
        length = l;
        width = w;
        height = h;
    }
    void volume() { cout << length * width * height << endl; }
};
int main() {
    int l, w, h;
    while (cin >> l >> w >> h) {
        Box box(l, w, h);
    }
    return 0;
}
