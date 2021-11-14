#include <stdio.h>
#include <climits>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int mx = 0, mi = INT_MAX;
  while(n--) {
    int idx;
    scanf("%d", &idx);
    if(mx < idx)  mx = idx;
    if(mi > idx)  mi = idx;
  }
  printf("%d", mx * mi);
  return 0;
}
