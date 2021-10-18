#include <stdio.h>
#include <algorithm>
using namespace std; 

int main() {
  int n;
  int dp[3][2] = {{0, 0}, {0, 0}, {0, 0}};
  scanf("%d", &n);
  scanf("%d%d%d", &dp[0][0], &dp[1][0], &dp[2][0]);  
  dp[0][1] = dp[0][0]; dp[1][1] = dp[1][0]; dp[2][1] = dp[2][0];  
  
  for(int i = 1; i < n; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int c1[2], c2[2], c3[2];
    c1[0] = dp[0][0]; c1[1] = dp[0][1];
    c2[0] = dp[1][0]; c2[1] = dp[1][1];
    c3[0] = dp[2][0]; c3[1] = dp[2][1];

    dp[0][0] = max(a + c1[0], a + c2[0]);
    dp[1][0] = max(b + c1[0], max(b + c2[0], b + c3[0]));
    dp[2][0] = max(c + c2[0], c + c3[0]);
    
    dp[0][1] = min(a + c1[1], a + c2[1]);
    dp[1][1] = min(b + c1[1], min(b + c2[1], b + c3[1]));
    dp[2][1] = min(c + c2[1], c + c3[1]);     
  }

  printf("%d %d", max(dp[0][0], max(dp[1][0], dp[2][0])), min(dp[0][1], min(dp[1][1], dp[2][1])));

  return 0;

}