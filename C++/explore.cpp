#include <cstring>
#include <iostream>
using namespace std;
int i = 0;
class Name {
  public:
    Name(char *pN);
    Name(const Name &); // 复制构造函数

    Name operator=(const Name); // 重载赋值运算符
    ~Name();

  protected:
    char *pName;
    int size;
};
Name::Name(char *pN) {
    cout << pN << " created using a str" << endl << endl;
    pName = new char[strlen(pN) + 1];
    if (pName != 0)
        strcpy(pName, pN);
    size = strlen(pN);
}
Name::Name(const Name &Obj) // 复制构造函数
{
    pName = new char[strlen(Obj.pName) + 1];
    if (pName != 0)
        strcpy(pName, Obj.pName);
    size = Obj.size;
    cout << Obj.pName << " created using copy" << endl;
}
Name Name::operator=(const Name Obj) // 重载赋值运算符
{
    cout << Obj.pName << " set using =" << endl;

    delete[] pName;
    pName = new char[strlen(Obj.pName) + 1];
    if (pName != 0)
        strcpy(pName, Obj.pName);
    size = Obj.size;
    return *this;
}
Name::~Name() {
    cout << ++i;
    cout << pName << " destroyed\n" << endl;
    pName[0] = '\0';
    delete[] pName;
    size = 0;
}

int main() {
    Name Obj1("AAA");
    Name Obj2("BBB"); // 调用复制构造函数
    Name Obj3("CCC");

    // The following has produced six objects!
    Obj3 = Obj2 = Obj1; // 调用重载赋值运算符函数

    ////The following has produced seven objects!
    // Obj2 = Obj1;		// 调用重载赋值运算符函数
    // Obj3 = Obj2;		// 调用重载赋值运算符函数

    // Name Obj1( "aaaa" ) ;
    // Name Obj2( "bbbb" ) ;		// 调用复制构造函数
    // Name Obj3( "cccc" ) ;
    // Name Obj4( "dddd" );
    // Obj4 = Obj3 = Obj2 = Obj1 ;		// 调用重载赋值运算符函数

    ////Obj2 = Obj1;
    ////Obj3 = Obj2;
    ////Obj4 = Obj3 ;
}
