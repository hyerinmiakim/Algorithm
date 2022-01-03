#include <stdio.h>
#include <string>
using namespace std;
// 10:02
long long arr[10000001];  // 10 20 21 30 31 32 40 41 42
int depth = 10, N;
void Diminish() {
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < (arr[i]%10); j++) {
      if(depth > N) return;
      arr[depth++] = (arr[i] * 10) + j;
    }
  }
}
int main(){
  scanf("%d", &N);
  
  if(N <= 9) {
    printf("%d", N);
    return 0;
  }
  else if (N >= 1023) {
    printf("-1");
    return 0;
  }

  for(int i = 0; i <= 9; i++) arr[i] = i;
  Diminish();
  printf("%lld", arr[N]);
  return 0;
}
