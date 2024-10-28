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
    // input /
    // test area
    sort(batch.begin(), batch.end());

    int min_diff = abs(batch[1] - batch[0]);
    for (int i = 1; i < batch_size; i++)
    {
      min_diff = min(abs(batch[i] - batch[i - 1]), min_diff);
    }

    int max_diff = batch[batch_size - 1] - batch[0];

    cout << min_diff << ' ' << max_diff << endl;

    // test area /
  } // main loop /
  return 0;
}
