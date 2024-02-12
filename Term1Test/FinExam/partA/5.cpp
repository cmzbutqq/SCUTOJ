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

// 1D dynamic input
int main()
{
  int n;
  while (cin >> n)
  { // main loop
    // input
    vector<pair<int, float>> input(2 * n), tops(0);
    for (int i = 0; i < (2 * n); i++)
      cin >> input[i].first >> input[i].second; // first: int id; second:float score
    // input /
    // test area
    for (int count = 0; count < 3; count++)
    {
      float max = input[0].second;
      int max_i = 0;

      int index;
      for (index = 0; index < 2 * n; index++)
      {
        if (input[index].second >= max)
        {
          for (auto item : tops) // check recorded or not
          {
            if (item.first == input[index].first)
              goto skip;
          }
          max = input[index].second;
          max_i = index;
        }
      skip:;
      }
      tops.push_back({input[max_i].first, max});
    }
    // out
    for (auto item : tops)
    {
      cout << item.first << ' ' << fixed << setprecision(2) << item.second << endl;
    }
    // test area /
  } // main loop /
  return 0;
}
