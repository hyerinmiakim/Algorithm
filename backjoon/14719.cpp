#include <stdio.h>
#include <algorithm>
using namespace std;
// 14:30
int main(){
  // 고이기 위한 조건: 자신보다 작은 값이 한번 이상 나오고, 다시 자기 자시놉다 크거나 같은게 등장했을 경우
  int H, W;
  scanf("%d%d", &H, &W);
  int water[502] = {0, };

  for(int i = 0; i < W; i++){
    scanf("%d", &water[i]);
  }
  
  int answer = 0;
  for(int i = 1; i < W-1; i++){
    int cur = water[i];
    int left = 0, right = 0;
    for(int j = i-1; j >= 0; j--)
      if(left < water[j]) left = water[j];
    for(int j = i+1; j <= W; j++)
      if(right < water[j]) right = water[j];
    
    int target = min(right, left);  // 둘 중 작은 곳 만큼 웅덩이 이룰 수 있음.
    answer += max(0, target - cur); // 물이 잠기지 않는 상황이면 0이 된다.
  }
  printf("%d", answer);
  return 0;
}
