#include <iostream>
#include <algorithm>
using namespace std;

char arr[1001][1001];
int dp[1001][1001]; // dp[n]: (왼쪽, 왼쪽대각선위, 위) 중 가장 작은 값에 +1. 세 조건이 다 1에 만족해야지 사각형을 만들수 있기 때문

int main() {
  int n, m, _max=0;
  cin >> n >> m;

  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
      cin >> arr[i][j];

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(arr[i][j] == '1') {
        dp[i][j] = min (dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
      }
      if (dp[i][j] > _max)  _max = dp[i][j]; 
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++)
      cout << dp[i][j];
    cout << '\n';
  }
  cout << _max * _max << '\n';
  return 0; 
}
