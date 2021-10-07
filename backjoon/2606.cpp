#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
int n, m;
bool check[101];
vector<int> virus[101];
int cnt = 0;

void dfs(int x) {
  check[x] = true;
  for(int i = 0; i < virus[x].size(); i++) {
    if(virus[x][i] && check[virus[x][i]] == false) {
      dfs(virus[x][i]);
      cnt++;
    }
  }
}
void bfs(int x) {
  check[x] = true; 
  queue<int> que;
  que.push(x);
  while(!que.empty()) {
    int tmp = que.front();
    que.pop();
    for(int i = 0; i < virus[tmp].size(); i++) {
      if (check[virus[tmp][i]] == false && virus[tmp][i]) {
        que.push(virus[tmp][i]);
        check[virus[tmp][i]] = true;
        cnt++;
      }
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);

  for(int i = 0; i < m; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    virus[a].push_back(b);
    virus[b].push_back(a);
  }
  //dfs(1); //only 1
  bfs(1);
  printf("%d\n", cnt);
  return 0;
}