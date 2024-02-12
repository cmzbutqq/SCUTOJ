#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string bookname;
    int price;
    int number;

public:
    Book(string bookname, int price, int number)
        : bookname(bookname), price(price), number(number) { display(); }
    void display()
    {
        cout << bookname << " " << price << " " << number << endl;
    }
    void borrow()
    {
        number--;
        cout << number << endl;
    }
    void restore()
    {
        number++;
        cout << number << endl;
    }
    void showTotalCost()
    {
        cout << number * price << endl;
    }
};

void act(char command, Book &book)
{
    switch (command)
    {
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

int main()
{
    string input_name;
    int input_price, input_number;
    char input_action[5];
    while (cin >> input_name >> input_price >> input_number >> input_action[0] >> input_action[1] >> input_action[2] >> input_action[3] >> input_action[4])
    {
        Book book(input_name, input_price, input_number);
        for (int i = 0; i < 5; ++i)
        {
            act(input_action[i], book);
        }
    }
    return 0;
}