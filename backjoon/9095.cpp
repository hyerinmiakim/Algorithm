#include <stdio.h>
using namespace std;
int dp[13];
int main()
{
  int N;
  scanf("%d", &N);
  while(N--)
  {
    int n;
    scanf("%d", &n);
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int j = 4; j <= n; j++) 
      dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    printf("%d\n", dp[n]);
  }
  return 0;
}