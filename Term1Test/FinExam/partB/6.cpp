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
  int count1, count5, count10,
      price, pay1, pay5, pay10;
  cin >> count1 >> count5 >> count10;
  while (cin >> price >> pay1 >> pay5 >> pay10)
  { // main loop
    // test area
    int to_return = 1 * pay1 + 5 * pay5 + 10 * pay10 - price;
    count1 += pay1;
    count5 += pay5;
    count10 += pay10;
    while (to_return > 0)
    {
      if (to_return >= 10 && count10 > 0)
      {
        to_return -= 10;
        count10--;
        continue;
      }
      if (to_return >= 5 && count5 > 0)
      {
        to_return -= 5;
        count5--;
        continue;
      }
      if (to_return >= 1 && count1 > 0)
      {
        to_return -= 1;
        count1--;
        continue;
      }
    }
    cout << count1 << ' ' << count5 << ' ' << count10 << endl;
    // test area /
  } // main loop /
  return 0;
}
