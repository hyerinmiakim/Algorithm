#include <stdio.h>
using namespace std;

int root[1000002]; //root[자식] = 부모
int Findroot(int x) {
  if(root[x] == x)  return x;
  return root[x] = Findroot(root[x]);
}


void Union(int a, int b) {
  
  a = Findroot(a);
  b = Findroot(b);
  if(a != b) {
    root[b] = a;
  }
  return;
}
int main()
{ 
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; i++)
    root[i] = i;

  for (int i = 0; i < m; i++) {
    int idx, a, b;
    scanf("%d%d%d", &idx, &a, &b);

    if(!idx) {  //합친다 -> Union
      Union(a, b);
    }

    else {  //판별 -> Find
      if(Findroot(b) == Findroot(a))  printf("YES\n");
      else  printf("NO\n");
    }
  }
  return 0;
}