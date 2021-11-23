#include <stdio.h>
using namespace std;
// 12:23 - 12:31
int main(){
  int a, b;
  scanf("%d%d", &a, &b);
  int target;
  if(a > b) target = b;
  else target = a;
  // 최대공약수: 둘 중 작은 값 까지 for 문 돌면서, 동시에 나눠지는 애들 중 제일 큰 아이
  // 최소 공배수 : 최대 공약수 * 수 / 최대공약수
  int mx = 1, mi;
  for(int i = 1; i <= target; i++) {
    if(a%i == 0 && b%i == 0) {
      if(mx < i) mx = i;
    }
  }
  
  mi = mx * (a/mx) * (b/mx);
  printf("%d\n%d",mx, mi);
  return 0;
}
