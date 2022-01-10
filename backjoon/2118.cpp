#include <stdio.h>
#include <algorithm>
using namespace std;
// 17:21
int arr[50001];
int main(){
  int n, S = 0; 
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    S += arr[i];
  }
  
  int left = 1, right = 2;
  int answer = 0, sum = arr[left];
  
  while(left <= right && right <= n) {
    // 시계방향, 반시계 방향 중 저 작은 쪽
    int len = min(sum, S - sum);
    // 길이가 전체 길이의 반이라면 섬 이동
    if(S - sum <= len) {
      sum -= arr[left++]; 
    }
    else {
      sum += arr[right++];
    }
    answer = max(answer, len);
  }

  printf("%d", answer);
  return 0;
}


