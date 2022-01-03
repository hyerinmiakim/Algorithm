#include <iostream>
#include <algorithm>
using namespace std;
// 21:22
bool dfs(string s)
{
  for(int i = 1; i < s.size(); i++) {
    if(s[i] == s[i-1])  return false;
  }
  return true;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  string str;
  int answer = 0;
  cin >> str;
  sort(str.begin(), str.end()); // next_permutation할 때는 무조건 sort!!!!!!!!!!!!
  do {
    if(dfs(str)) answer += 1;
  } while(next_permutation(str.begin(), str.end()));
  cout << answer;
  return 0;
}
