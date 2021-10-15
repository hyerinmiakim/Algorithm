#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[101];  // N번 눌렀을 때 출력할 수 있는 A 갯수의 최댓값을 가진다
int main() {
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= 6; i++)
    dp[i] = i;

  for(int i = 7; i <= 100; i++) {
    for(int j = 1; j <= i - 3; j++) {
      dp[i] = max(dp[i], max((dp[i-1] + 1), (dp[i - (j+2)] * (j+1))));
    }
  }
  printf("%lld\n", dp[n]);
  return 0;
}