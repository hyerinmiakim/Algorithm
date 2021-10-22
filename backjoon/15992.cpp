#include <stdio.h>
using namespace std;
constexpr int mod = 1e9 + 9;
int dp[1001][1001];
int main()
{
  dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
  dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 0;
  dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
  for(int i = 4; i <= 1000; i++)
    for(int j = 1; j <= 1000; j++) 
      dp[i][j] = ((dp[i-1][j-1] + dp[i-2][j-1]) %mod + dp[i-3][j-1])%mod;
  
  int N;
  scanf("%d", &N);
  while(N--)
  {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d\n", dp[n][m]);
  }
  return 0;
}