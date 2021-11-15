#include <stdio.h>
using namespace std;

int main(){
  int n;
  int mx = -1000000, mi = 1000001;
  scanf("%d", &n);
  while(n--) {
    int idx;
    scanf("%d", &idx);
    if(mx < idx) mx = idx;
    if(mi > idx) mi = idx;
  }
  printf("%d %d", mi, mx);
  return 0;
}
