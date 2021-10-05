#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  vector<int> queue;
  string s;

  int n, cnt = 1;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int idx;
    cin >> idx;

#if 1

    for (int i = 0; i < n; i++)
    {
      int idx;
      cin >> idx;

      /* 입력받은 데이터까지 ++ */
      while (cnt <= idx)
      {
        s += '+';
        queue.push_back(cnt);
        cnt += 1;
      }
      /* 만약 같다면 */
      if (queue.back() == idx)
      {
        queue.pop_back();
        s += '-';
      }
      else
      {
        cout << "NO";
        return 0;
      }
    }
#else
    for (int i = n - 1; i >= 0; i--)
    {
      if (stack[i] == n)
      {
        s += '+';
        for (int j = 0; j < n - i; j++)
        {
          s += "-";
        }
        break;
      }
      else
      {
        if (stack[i + 1] < stack[i])
        {
          if (stack[i] == ++cnt)
          {
            s += '+';
          }
          else
          {
            for (int j = 0; j < stack[i] - cnt; j++)
            {
              s += "+";
            }
            for (int j = 0; j < stack[i] - cnt; j++)
            {
              s += "-";
            }
            s += "+";
            cnt = stack[i];
          }
        }
        else
        {
          cout << "NO";
          return 0;
        }
      }
    }
#endif
    for (char c : s)
      cout << c << '\n';
    return 0;
  }