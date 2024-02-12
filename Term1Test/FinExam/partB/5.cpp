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
  int batch_size;
  while (cin >> batch_size)
  { // main loop
    // input
    vector<int> batch(batch_size);
    for (int i = 0; i < batch_size; i++)
      cin >> batch[i];
    int target;
    cin >> target;
    // input /
    // test area
    bool flag = false;
    for (int i = 0; i < batch_size; i++)
    {
      for (int j = i + 1; j < batch_size; j++)
      {
        if (batch[i] + batch[j] == target)
          flag = true;
      }
    }

    if (flag)
      cout << "TRUE" << endl;
    else
      cout << "FALSE" << endl;

    // test area /
  } // main loop /
  return 0;
}
