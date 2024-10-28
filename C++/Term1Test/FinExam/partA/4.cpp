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
  int x, y;
  int chess[10][9] = {0};
  while (cin >> x >> y)
  { // main loop
    // input
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 9; j++)
        cin >> chess[i][j];
    }
    // input /
    // test area

    // fill
    for (int i = x + 1, j = y, meet = 0; i < 10; i++)
    {
      if (chess[i][j] != 0)
        meet++;
      if (chess[i][j] == 0 && meet == 0)
        chess[i][j] = 3;
      if (chess[i][j] == 2 && meet == 2)
        chess[i][j] = 3;
      if (meet==3)
        break;
    }
    for (int i = x - 1, j = y, meet = 0; i >= 0; i--)
    {
      if (chess[i][j] != 0)
        meet++;
      if (chess[i][j] == 0 && meet == 0)
        chess[i][j] = 3;
      if (chess[i][j] == 2 && meet == 2)
        chess[i][j] = 3;
      if (meet==3)
        break;
    }
    for (int i = x, j = y + 1, meet = 0; j < 9; j++)
    {
      if (chess[i][j] != 0)
        meet++;
      if (chess[i][j] == 0 && meet == 0)
        chess[i][j] = 3;
      if (chess[i][j] == 2 && meet == 2)
        chess[i][j] = 3;
      if (meet==3)
        break;
    }
    for (int i = x, j = y - 1, meet = 0; j >= 0; j--)
    {
      if (chess[i][j] != 0)
        meet++;
      if (chess[i][j] == 0 && meet == 0)
        chess[i][j] = 3;
      if (chess[i][j] == 2 && meet == 2)
        chess[i][j] = 3;
      if (meet==3)
        break;
    }
    // out
    for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 9; j++)
        cout << chess[i][j];
      cout << endl;
    }
    // test area /
  } // main loop /
  return 0;
}
