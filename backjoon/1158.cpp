#include <stdio.h>
#include <queue>
using namespace std;

int main(){
  int n, k;
  int cnt = 1;
  scanf("%d%d", &n, &k);
  queue<int> que;
  for(int i = 1; i <= n; i++)
    que.push(i);
  printf("<");
  while(!que.empty()) {
    int start = que.front();
    que.pop();
    if(cnt == k) {
      if(que.empty()) printf("%d", start);
      else printf("%d, ", start);
      cnt = 0;
    }
    else que.push(start);
    cnt+=1;
  }
  printf(">");
  return 0;
}
