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
  int m, n, degree;
  while (cin >> m >> n)
  { // main loop
    // input
    bool image[m][n];
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> image[i][j];
      }
    }
    cin >> degree;
    // input /
    // test area
    switch (degree)
    {
    case 90:
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          cout << image[m - 1 - j][i] << ((j == m - 1) ? "\n" : " ");
        }
      }
      break;
    }
    case 180:
    {
      for (int i = 0; i < m; i++)
      {
        for (int j = 0; j < n; j++)
        {
          cout << image[m - 1 - i][n - 1 - j] << ((j == n - 1) ? "\n" : " ");
        }
      }
      break;
    }
    case 270:
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          cout << image[j][n - 1 - i] << ((j == m - 1) ? "\n" : " ");
        }
      }
      break;
    }
    default: // this shouldn't be run
      throw("wtf");
    }
    // test area /
  } // main loop /
  return 0;
}
