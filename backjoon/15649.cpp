#include <stdio.h>
using namespace std;
// 15: 30
int N, M;
bool check[9];
int arr[9];

void dfs(int cnt) {
  if(cnt == M) {
    for(int i = 0; i < M; i++)
      printf("%d ", arr[i]);
    printf("\n");
    return;
  }

  for(int i = 1; i <= N; i++) {
    if(check[i] == false) {
      check[i] = true;
      arr[cnt] = i;
      dfs(cnt+1);
      check[i] = false;
    }
  }
}
int main(){
  scanf("%d%d", &N, &M);
  dfs(0);
  return 0;
}
