#include <iostream>
#include <iomanip>

#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#include <cmath>
#include <memory> //unique_ptr shared_ptr

using namespace std;

int main()
{
  string str;
  while (cin >> str)
  { // main loop
    // test area
    string layer = "";
    for (char c : str)
    {
      if (c == '(' || c == '{' || c == '[')
      {
        layer += c;
      }
      else if (c == ')' && *layer.rbegin() == '(')
      {
        layer.pop_back();
      }
      else if (c == ']' && *layer.rbegin() == '[')
      {
        layer.pop_back();
      }
      else if (c == '}' && *layer.rbegin() == '{')
      {
        layer.pop_back();
      }
      else
      {
        cout << "false" << endl;
        goto end;
      }
    }
    cout << "true" << endl;
  end:;
    // test area /
  } // main loop /
  return 0;
}
