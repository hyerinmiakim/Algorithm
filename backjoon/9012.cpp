#include <iostream>
#include <vector>
using namespace std;
//1:18
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int n;
  cin>>n;
  while(n--) {
    string str;
    vector<char> stk;
    cin >> str;
    stk.clear();
    bool flag = true;
    for(int i = 0; i < str.size(); i++) {
      if(str[i] == '(') {
        stk.push_back('(');
      }
      else {
        if(stk.empty()) {
          flag =false;
          break;
        }
        if(stk.back() == '(') {
          stk.pop_back();
        }
        else {
          flag = false;
          break;
        } 
      }
    }
    if(flag && stk.empty())
      printf("YES\n");
    else printf("NO\n");

  }
  return 0;
}
