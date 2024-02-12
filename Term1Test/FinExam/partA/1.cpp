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
  string input;
  while (cin >> input)
  { // main loop
    // test area
    int upper = 0, lower = 0, num = 0;
    for (char c : input)
    {
      if ('A' <= c && c <= 'Z')
        ++upper;
      if ('a' <= c && c <= 'z')
        ++lower;
      if ('0' <= c && c <= '9')
        ++num;
    }

    cout << upper << ' ' << lower << ' ' << num << endl;
    // test area /
  } // main loop /
  return 0;
}
