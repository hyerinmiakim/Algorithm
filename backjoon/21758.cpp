#include <stdio.h>
using namespace std;

int main(){
  // 벌이 있는 위치 
  // 현재 위치에서 벌이 있는 곳 까지 날아간다.
  // 자신의 위치만 제외하고 모두 먹을 수 이싸.
  int n; 
  int bee[100001] = {0, };
  long long sum[100001] = {0, };
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    scanf("%d", &bee[i]);
    sum[i] = sum[i-1] + bee[i];
  }
  // 각 자리마다 처음~현재까지 누적합 
  // 총합 - 현재 누적합 - 겹치는 인덱스 
  long long answer = 0;
  // 벌벌꿀
  for(int i = 2; i <= n; i++) {
    long long honey = (sum[n] - bee[1] - bee[i]) + (sum[n] - sum[i]);
    if(answer < honey) answer = honey;
  }
  // 꿀벌벌
  for(int i = 2; i < n; i++) {
    long long honey = sum[i-1] + (sum[n-1] - bee[i]);
    if(answer < honey) answer = honey;
  }
  //벌꿀벌
  for(int i = 2; i < n; i++) {
    long long honey = (sum[i] - bee[1]) + (sum[n-1] - sum[i-1]);
    if(answer < honey) answer = honey;
  }

  printf("%lld", answer);

  return 0;
}
