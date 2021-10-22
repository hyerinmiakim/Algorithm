#include <stdio.h>
using namespace std;
int dp[10001][3];
int main()
{
  int N;
  scanf("%d", &N);
  dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
  dp[2][1] = 1; dp[2][2] = 1; dp[2][3] = 0;
  dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;
  for (int i = 0; i < N; i++)
  {
    int num;
    scanf("%d", &num);
    
    /*for(int j = 4; j <= num; j++) {
      dp[j][1] = dp[j-1][1];
      dp[j][2] = dp[j-2][1] + dp[j-2][2];
      dp[j][3] = dp[j-3][1] + dp[j-3][2] + dp[j-3][3];
    }*/
    for(int j = 4; j <= num; j++) {
      for(int i = 1; i <= 3; i++) {
        int tmp = 0;
        for(int k = 1; k <= i; k++)
          tmp += dp[j-i][k];
        dp[j][i] = tmp;
      }
    }

    printf("%d\n", dp[num][1] + dp[num][2] + dp[num][3]);
  }
  return 0;
}