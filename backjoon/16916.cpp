#include <iostream>
#include <vector>
using namespace std;

string S,P;
int answer;

#if 0 // Brute force
bool isSubString(int idx) {
  int num = 1;
  for(int i = 1; i < P.size(); i++) {
    if(S[idx + i] != P[num]) {
      return false;
    }
    num+=1;
  }
  return true;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> S >> P;
  for(int i = 0; i < S.size(); i++) {
    if(P[0] == S[i]) {
      answer = isSubString(i);
      cout << answer << "\n";
      if(answer == 0) break;
    }
  }
  return 0;
}
#else // KMP
vector<int> createTable(string str) {
  int slen = str.size();
  vector<int> table(slen, 0);
  table[0] = -1;

  int idx = 0;
  for(int i = 1; i < slen; i++) {
    while(str[idx] != str[i] && idx > 0)
      idx = table[idx];

    if(str[idx] == str[i]) table[i+1] = ++idx;
  }

  return table;

}
void KMP(string src, string dst) {
  
  // 최대 경계 너비 테이블 채우기
  auto table = createTable(dst);
  int idx = 0, dist = 0;
  while(1) {
    idx = 0;
    if((idx + dist) + dst.size() > src.size()) {
      cnt+=1;
      idx++;

      if()
    }
  }

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  cin >> S >> P;
  KMP(S, P);
  return 0;
}
#endif