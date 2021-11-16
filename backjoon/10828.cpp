#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n;
  stack<int> stk;
  cin >> n; 
  while(n--) {
    string str;
    cin >> str;
    if(str == "top")
    {
      if(stk.empty()) cout << "-1\n";
      else cout << stk.top() << "\n";
    }
    else if (str == "size")
    {
      if(stk.empty()) cout << "0\n";
      else cout << stk.size() << "\n";
    }
    else if (str == "empty")
    {
      cout << stk.empty() << "\n";
    }
    else if (str == "pop")
    {
      if(stk.empty()) cout << "-1\n";
      else {
        cout << stk.top() << "\n";
        stk.pop();
      }
    }
    else {  //push
      int x;
      cin >> x;
      stk.push(x);
    }
  }
  return 0;
}
