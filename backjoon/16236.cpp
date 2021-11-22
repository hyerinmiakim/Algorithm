#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
// 15:32
#define pii pair<int, pair<int, int> >
int n, babyX, babyY;
int baby = 2; // 아기 상어의 크기 

int board[21][21];
int check[21][21];
int way[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}; // 시계 반대방향
vector<pii> fish; // 아기 상어가 먹는 먹이 (거리, 위치) 

bool cmp (pii a, pii b) {
  // 1. 거리 작은 순
  if(a.first == b.first) {
    // 2. 높이
    if(a.second.first == b.second.first)
      // 3. 가로
      return a.second.second < b.second.second;
    return a.second.first < b.second.first;
  }
  return a.first < b.first;
}
void bfs(int ax, int ay) {
  queue<pair<int, int> > que; // 아기 상어의 위치
  que.push({ax, ay});
  fish.clear();
  memset(check, false, sizeof(check));

  while(!que.empty()) {
    int x = que.front().first;
    int y = que.front().second;
    que.pop();
    
    for(int i = 0; i < 4; i++) {
      int cx = x + way[i][0];
      int cy = y + way[i][1];
      // 1. 먹지 못하는 조건들 continue
      if(cx <= 0 || cx > n || cy <= 0 || cy > n) continue;
      if(check[cx][cy]) continue;
      if(board[cx][cy] > baby) continue;

      // 2. 지나갈 수 있는 고기인지
      if(board[cx][cy] >= 0 && board[cx][cy] <= baby) {
        check[cx][cy] = check[x][y] + 1;
        // 3. 먹을 수 있는 고기인지
        if(board[cx][cy] > 0 && board[cx][cy] < baby) {
          fish.push_back({check[cx][cy], make_pair(cx, cy)});
        }
        que.push({cx, cy});
      }
    }
  }
}

int main(){
  int ate = 0, time = 0;
  scanf("%d", &n);
  for(int i = 1; i<=n; i++)
    for(int j = 1; j <= n; j++) {
      scanf("%d", &board[i][j]);
      if(board[i][j] == 9) {
        board[i][j] = 0;
        babyX = i; babyY = j;
      } 
    }

  while(true) {
    bfs(babyX, babyY);
    if(fish.empty()) break;
    sort(fish.begin(), fish.end(), cmp); // 거리, 높이, 너비 순으로 정렬
    ate += 1;
    int topFishX = fish.front().second.first;
    int topFishY = fish.front().second.second;
    time += fish.front().first;
    
    board[topFishX][topFishY] = 0;
    babyX = topFishX; babyY = topFishY;
    if(baby == ate)
    {
      baby += 1;
      ate = 0;
    }
  }
  
  printf("%d", time); 
  return 0;
}
