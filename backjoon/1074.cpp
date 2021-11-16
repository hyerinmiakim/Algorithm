#include <stdio.h>
#include <cmath>
using namespace std;
// 9: 32
int n, R, C, ans;
void Z(int x, int y, int size) {
  printf("start from: (%d, %d), size: %d, ans: %d\n", x, y, size, ans);
  if(x == R && y == C) {
    printf("%d", ans);
    return;
  }
  // 찾고자 하는 값이 현재 좌표와 같은 분면?
  if(x <= R && R < x + size && y <= C && C < y + size ) {
    // 현재 분면에서 한번 더 쪼갠다
    printf("같은 분면! (%d, %d),, size: %d\n", x, y, size);
    int half = size/2;
    Z(x, y, half);
    Z(x, y+half, half);
    Z(x + half, y, half);
    Z(x + half, y + half, half);
  }
  else {
    // 아니라면(다른 분면에 있다면 사이즈만 더해줌)
    printf("out of range: %d\n", ans);
    ans += size * size;
  }
}
int main(){
  scanf("%d%d%d", &n, &R, &C);
  Z(0, 0, (1 << n));  //제곱의 신박한 방법.. 
 
  return 0;
}
