#include <stdio.h>
using namespace std;
#define MAX 100001
// 15:03
int main(){
  int n, s; 
  int arr[MAX];
  scanf("%d%d", &n, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int left = 0, right = 0, sum = 0, answer = MAX;
  while(right <= n) {
    if(sum < s) {
      sum += arr[right++];
    }

    else if (sum >= s) {
      int len = right - left;
      sum -= arr[left++];
      if(sum < 0) {
        answer = -1;
        break;
      }
      if(len < answer) answer = len;
    }
  }
  if(answer == MAX) answer = 0;
  else if (answer < 0) answer = 1;
  printf("%d", answer);
  return 0;
}
