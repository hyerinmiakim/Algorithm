#include <stdio.h>
#include <vector>
using namespace std;
// 13;44
int main(){
  int n, K; 
  bool used[102] = { false, };
  vector<int> plugs;
  int number[102] = {0, };
  scanf("%d %d", &n, &K);
  
  int answer = 0, plugslen = 0;

  for(int i = 1; i <= K; i++) {
    scanf("%d", &number[i]);
  }
  for(int i = 1; i <= K; i++) {
    int cur = number[i];
    // 이미 있는 것이라면 통과 
    if(used[cur] == true) continue;
    if(plugslen == n) {
      // 가득 차있다면, 덜 사용되는 애를 제거하고, 카운팅해준다.
      // 제거 조건: 이후에 덜 사용하는 애들이 나오는 것.  
      //printf("빠져야 할 아이 탐색 : %d\n",cur);
      int plugIdx = 0, last = 0;  // 플러그에 있는 애들 중.. 가장 나중에 사용되는 애를 제거한다(OPT 알고리즘)
      
      // 플러그에 꽂혀있는 애들 마다 다시 사용되기 전 까지 카운트를 해주면 가장 나중에 사용되는 애를 고를 수 있다. 
      for(int j = 0; j < plugslen; j++) {
        int cnt = 0;
        for(int k = i+1; k <= K; k++) {
          if(plugs[j] == number[k]) break;
          cnt+=1;
        }
        if(cnt > last) {
          last = cnt; 
          plugIdx = j;
        }
      }
      //printf("가장 적게 사용될 플러그: %d, 횟수: %d\n", plugs[plugIdx], last);
      used[plugs[plugIdx]] = false;
      plugs[plugIdx] = cur;
      used[cur] = true;
      answer += 1;
    }
    else {
      // 비어있다면 빈 곳에 추가 
      plugs.push_back(cur);
      used[cur] = true;
      plugslen += 1;
    }
  }
  printf("%d", answer);

  return 0;
}

//1 2 3 4 3 4 2 2