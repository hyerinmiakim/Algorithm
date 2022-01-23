#include <stdio.h>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
// 16:33
int L;
bool check[301][301];
int pos[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1},
                {2, -1}, {-1, -2}, {1, -2}, {-2, -1}};

/*void dfs(int x, int y, int dstX, int dstY, int dist) {
  if(x == dstX && y == dstY) {
    if(answer > dist) answer = dist;
    printf("dfs dist : %d\n", dist);
    return;
  }

  check[x][y] = true;
  for(int i = 0; i < 9; i++) {
    int cx = x + pos[i][0];
    int cy = y + pos[i][1];
    if(cx >= L || cx < 0 || cy >= L || cy < 0) continue;
    if(check[cx][cy]) continue;
    dfs(cx, cy, dstX, dstY, dist + 1);
  }

  return;

}*/
void bfs(int x, int y, int dstX, int dstY) {
  queue<pair<pair<int, int>, int> > que;
  que.push({{x, y}, 0});
  check[x][y] = true;
  while(!que.empty()) {
    pair<int, int> start = que.front().first;
    int dist = que.front().second;
    que.pop();
    if(start.first == dstX && start.second == dstY) {
      printf("%d\n", dist);
      return;
    }
    for(int i = 0; i < 8; i++) {
      int cx = start.first + pos[i][0];
      int cy = start.second + pos[i][1];
      if(cx >= L || cx < 0 || cy >= L || cy < 0) continue;
      if(check[cx][cy]) continue;
      check[cx][cy] = true;
      que.push({{cx, cy}, dist+1});
    }
  }
  return;
}

int main(){
  int T; 
  scanf("%d", &T);
  while(T--) {
    pair<int, int> night;
    pair<int, int> target;
    scanf("%d", &L);
    scanf("%d%d", &night.first, &night.second);
    scanf("%d%d", &target.first, &target.second);

    memset(check, false, sizeof(check));
    bfs(night.first, night.second, target.first, target.second);
  }
  
  return 0;
}
