#include <iostream>
#include <string>
using namespace std;

class Book {
  private:
    string bookname;
    int price;
    int number;

  public:
    Book(string bookname, int price, int number)
        : bookname(bookname), price(price), number(number) {
        display();
    }
    void display() {
        cout << bookname << " " << price << " " << number << endl;
    }
    void borrow() { cout << --number << endl; }
    void restore() { cout << ++number << endl; }
    void showTotalCost() { cout << number * price << endl; }
};

void operate(char command, Book &book) {
    switch (command) {
    case 'B':
        book.borrow();
        break;
    case 'R':
        book.restore();
        break;
    case 'C':
        book.showTotalCost();
        break;
    }
}

int main() {
    string in_name;
    int in_price, in_number;
    char commands[5];
    while (cin >> in_name >> in_price >> in_number) {
        Book book(in_name, in_price, in_number);
        for (int i = 0; i < 5; i++)
            cin >> commands[i];
        for (char command : commands)
            operate(command, book);
    }
    return 0;
}