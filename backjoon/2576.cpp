#include <stdio.h>
using namespace std;

int main(){
  int odd = 0, mi = 101;
  for(int i = 0; i < 7; i++) {
    int idx;
    scanf("%d", &idx);
    if(idx % 2 == 1)  {
      odd += idx;
      if(mi > idx)  mi = idx;
    }
  }
  if(odd == 0)
    printf("-1\n");
  else {
    printf("%d\n%d", odd, mi);
  }
  return 0;
}
