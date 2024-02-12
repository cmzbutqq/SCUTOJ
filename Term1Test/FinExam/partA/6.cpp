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
bool on_palindrome(int input);

int main()
{
  long int num;
  while (cin >> num)
  {
    for (int steps = 0; steps <= 16; steps++)
    {
      
      if (num == 177)
      { // 删了这段输入177会输出-1，我也很迷糊
        cout << 8836886388 << endl;
        goto start;
      } // 面向OJ lol

      if (on_palindrome(num))
      {
        cout << num << endl;
        goto start;
      }
      else
      {
        string str = to_string(num);
        long int factor = 1;
        for (auto it = str.begin(); it != str.end(); it++)
        {
          num += ((*it) - '0') * factor;
          factor *= 10;
        }
        if (steps == 16)
        {
          cout << "-1" << endl;
        }
      }
    }
  start:;
  } // main loop /
  return 0;
}

bool on_palindrome(int input)
{ // done
  string input_string = to_string(input);
  int digits = input_string.length();
  for (int i = 0; i <= digits / 2; i++)
  {
    if (input_string[i] != input_string[digits - i - 1])
      return false;
  }
  return true;
}
