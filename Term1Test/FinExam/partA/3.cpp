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
  int length;
  while (cin >> length)
  { // main loop
    // input
    vector<int> heights(length);
    for (int i = 0; i < length; i++)
      cin >> heights[i];
    // input /
    // test area
    set<int> volumes = {};
    for (int i = 0; i < length; i++)
    {
      for (int j = i + 1; j < length; j++)
      {
        volumes.insert(
            (j - i) * min(heights[i], heights[j]));
      }
    }
    cout << *(--volumes.end()) << endl;
    // test area /
  } // main loop /
  return 0;
}
