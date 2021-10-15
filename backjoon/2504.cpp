#include <iostream>
#include <stack>
using namespace std;

stack<char> stk;
int main()
{
  int cnt = 1;
  int ans = 0;
  bool flag = true;
  string str;
  cin >> str;
  for(int i = 0; i < str.size(); i++) {
    if(str[i] == '(') {
      cnt *= 2;
      stk.push('(');
    }
    else if(str[i] == '[') {
      cnt *= 3;
      stk.push('[');
    }
    else if (str[i] == ')') {
      if(stk.empty() || stk.top() != '(') {
        flag = false;
        break;
      }
      if(str[i-1] == '(') {
        ans += cnt;
      }
      cnt /= 2;
      stk.pop();
    }
    else if (str[i] == ']') {
      if(stk.empty() || stk.top() != '[') {
        flag = false;
        break;
      }
      if(str[i-1] == '[') {
        ans += cnt;
      }
      stk.pop();
      cnt /= 3;
    }
   
  }
  
  if(!flag || !stk.empty())
    cout << "0\n";
  else
    cout << ans << "\n";
  return 0;
}