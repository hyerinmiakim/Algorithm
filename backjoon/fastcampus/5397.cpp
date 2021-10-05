#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  int n;
  vector<string> answer;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    string str;
    cin >> str;
#if 1
    vector<char> left;
    vector<char> right;
    for (int j = 0; j < str.size(); j++)
    {
      if (isalnum(str[j]))
      {
        left.push_back(str[j]);
      }
      
        if (str[j] == '<')
        {
          if (!left.empty())
          {
            char c = left.back();
            right.push_back(c);
            left.pop_back();
          }
        }
        else if (str[j] == '>')
        {
          if (!right.empty())
          {
            char c = right.back();
            left.push_back(c);
            right.pop_back();
          }
        }
        else if (str[j] == '-')
        {
          if (!left.empty())
          {
            left.pop_back();
          }
        }
    }
    string tmp;
    /* move right to left*/
    while(!right.empty()) {
      left.push_back(right.back());
      right.pop_back();
    }
    /* print left reverse (pop)*/
    while(!left.empty()) {
      tmp.push_back(left.back());
      left.pop_back();
    }
    /* re-order */
    reverse(tmp.begin(), tmp.end());
    answer.push_back(tmp);
  }
#else
    string s;
    int idx = 0;
    for (int j = 0; j < str.size(); j++)
    {
      if (str[j] == '-')
      {
        if (j - 1 >= 0 && (isdigit(str[j - 1]) || isalpha(str[j - 1])))
        {
          s.pop_back();
          idx--;
        }
      }
      else if (str[j] == '<')
      {
        if (j > 0 && (isdigit(str[j - 1]) || isalpha(str[j - 1])))
          idx--;
      }
      else if (str[j] == '>')
      {
        if (j < str.size() && (isdigit(str[j + 1]) || isalpha(str[j + 1])))
          idx++;
      }
      else if (isdigit(str[j]) || isalpha(str[j]))
      {
        s.insert(s.begin() + idx, str[j]);
        idx++;
      }
    }
    answer.push_back(s);
  }
#endif
  for (string s1 : answer)
    cout << s1 << endl;
  return 0;
}