#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//16:38
int N,K, answer;
vector<string> southStr;
bool alpha[27];
int canReadString() {
  int cnt = 0;
  for(string s : southStr) {
    bool check = true;
    for(int i = 0; i < s.size(); i++) {
      if(alpha[s[i]-'a'] == false) {
        check = false;
        break;
      }
    }
    if(check) cnt+=1;
  }
  return cnt;
}
void dfs(int idx, int cnt) {
  if(cnt == K) {
    // 문자열 중 읽을 수 있는 문자열 센다.
    answer = max(answer, canReadString());
    return;
  }
  for(int i = idx; i < 26; i++) {
    if(alpha[i] == false) {
      alpha[i] = true;
      dfs(i, cnt+1);
      alpha[i] = false;
    }
  }
  return;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> N >> K;
  if(K < 5) {
    cout << "0\n";
    return 0;
  }
  for(int i = 0; i < N; i++)
  {
    string str;
    cin >> str;
    southStr.push_back(str);
  }
  alpha['a' - 'a'] = true; alpha['n' - 'a'] = true; alpha['t' - 'a'] = true;
  alpha['i' - 'a'] = true; alpha['c' - 'a'] = true;
  K -= 5;
  dfs(0, 0);
  cout << answer << "\n";
  return 0;
}
