#include <stdio.h>
using namespace std;
int n;
int arr[1001];
int dp[1001];
int last[1001];

void func1(int n) {
  if(n == 0)  return;
  func1(last[n]);
  printf("%d ", arr[n]);
}
int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    dp[i] = 1;
  }
  int mx = 1;
  int mxi = 1;
  for(int i = 1; i <= n; i++) {
    for(int j = i-1; j >= 1; j--) {
      if(arr[j] < arr[i]) {
        if(dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
          last[i] = j;
          if(mx < dp[i]) {
            mx = dp[i];
            mxi = i;
          }
        }
      }
    }
  }

  printf("%d\n", mx);
  func1(mxi);
  return 0;
}
