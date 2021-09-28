#include <iostream>
using namespace std;

bool dp[101][1001];  //[곡의 갯수][곡 별 올릴 수 있는 데시벨]
int sound[101];

int main()
{
  int N, S, M;
  int result = -1;
   
  cin >> N >> S >> M;

  for (int i = 1; i <= N; i++)
    cin >> sound[i];

  dp[0][S] = true;

  for(int i = 0; i < N; i++) {
    for(int j = 0; j <= M; j++) {
      if(dp[i][j] == true)
      {
        if(j + sound[i+1] <= M)
          dp[i+1][j+sound[i+1]] = true;
        
        if (j - sound[i+1] >= 0)
          dp[i+1][j-sound[i+1]] = true;
      }
    }
  }
  
  for(int i = M; i >= 0; i--)
  {
    if(dp[N][i] == true) {
      result = i;
      break;
    }
  }
  cout << result;
  return 0;
}