#include <stdio.h>
#include <string>
#include <cmath>
using namespace std;

bool banList[10];

bool check(int cur) {

  string s = to_string(cur);
  for(int i = 0; i < s.size(); i++) {
    if(banList[s[i] - '0']) return false;
  }
  return true;
}
int main(){
  int idx, n;
  scanf("%d", &idx);
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    banList[a] = true;
  }

  int answer = abs(idx - 100);
  string target = to_string(idx);

  for(int i = 0; i <= 1000000; i++) {
    // 고장나지 않은 버튼이라면
    if(check(i)) {
      // 현재 수의 사이즈 + 타겟까지 +,-로만 갈 경우 
      int num = abs(idx - i) +(to_string(i).size());
      if(answer > num) answer = num;
    }
  }
  printf("%d\n", answer);
  return 0;
}
