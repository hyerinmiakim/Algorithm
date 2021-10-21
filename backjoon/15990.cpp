#include <iostream>
using namespace std;

constexpr int mod = 1e9 + 9;
long long dp[100001][3];  // dp[Num][idx]: Num을 만들 수 있는 경우의수 중 마지막이 idx로 끝나는 애들
int main()
{
  int N = 0, Num;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> Num;
    dp[1][1] = 1; dp[1][2] = 0; dp[1][3] = 0;
    dp[2][1] = 0; dp[2][2] = 1; dp[2][3] = 0;
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1;

    for (int i = 4; i <= Num; i++) {
      dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % mod;
      dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % mod;
      dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % mod;
    }
    printf("%lld\n", (dp[Num][1] + dp[Num][2] + dp[Num][3])%mod);
  }
  

  return 0;
} 