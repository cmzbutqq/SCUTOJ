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
  int size;
  while (cin >> size)
  { // main loop
    // input
    vector<int> salary(size);
    for (int i = 0; i < size; i++)
      cin >> salary[i];
    // input /
    // test area
    float sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++)
    {
      int s = salary[i];
      if (s <= 5000)
        continue;
      else if (s <= 8000)
        sum += 0.03 * (s - 5000);
      else if (s <= 17000)
        sum += 0.03 * (8000 - 5000) + 0.10 * (s - 8000);
      else if (s <= 30000)
        sum += 0.03 * (8000 - 5000) + 0.10 * (17000 - 8000) + 0.20 * (s - 17000);
      else if (s <= 40000)
        sum += 0.03 * (8000 - 5000) + 0.10 * (17000 - 8000) + 0.20 * (30000 - 17000) + 0.25 * (s - 30000);
      else if (s <= 60000)
        sum += 0.03 * (8000 - 5000) + 0.10 * (17000 - 8000) + 0.20 * (30000 - 17000) + 0.25 * (40000 - 30000) + 0.30 * (s - 40000);
      else if (s <= 85000)
        sum += 0.03 * (8000 - 5000) + 0.10 * (17000 - 8000) + 0.20 * (30000 - 17000) + 0.25 * (40000 - 30000) + 0.30 * (60000 - 40000) + 0.35 * (s - 60000);
      else
        sum += 0.03 * (8000 - 5000) + 0.10 * (17000 - 8000) + 0.20 * (30000 - 17000) + 0.25 * (40000 - 30000) + 0.30 * (60000 - 40000) + 0.35 * (85000 - 60000) + 0.45 * (s - 85000);
      count++;
    }

    cout << sum << ' ' << count << endl;
    // test area /
  } // main loop /
  return 0;
}
