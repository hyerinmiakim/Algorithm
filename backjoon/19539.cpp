#include <stdio.h>
// 15:34
using namespace std;

int main(){
  int n, times = 0, sum = 0;
  scanf("%d", &n);
  // 1. 총 높이의 합이 3의 배수여야 다 줄 수 있는 것. -> "일 day" 이기 때문에 나누어 떨어지는 정수여야 한다.
  // 2. 나무마다 2번씩 주었을 때의 횟수 누적합이 세번씩 줬을 때보다 크다면(여유가 있다는 뜻) yes 
  while(n--) {
    int tree;
    scanf("%d", &tree);
    sum += tree;  // 총 높이의 합
    times += (tree/2); // 2만큼 자라는 물뿌리개로 주었을 때의 횟수 
  }
  if(sum % 3 != 0) printf("NO\n");
  else {
    if(times >= (sum/3)) printf("YES\n");
    
    else printf("NO\n");
  }
  return 0;
}
