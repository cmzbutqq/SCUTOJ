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
  string str1, str2;
  while (cin >> str1 >> str2)
  { // main loop
    // test area
    if (str1 == str2)
    {
      cout << "No" << endl;
      continue;
    }

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1 == str2)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;

    // test area /
  } // main loop /
  return 0;
}
