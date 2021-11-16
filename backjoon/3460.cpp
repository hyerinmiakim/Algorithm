#include <stdio.h>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  while(n--) {
    int idx = 0, bits = 1;
    int cnt = 0;
    scanf("%d", &idx);
    while(bits <= idx) {
      bits = 1 << cnt;
      if(bits & idx) {
        printf("%d ", cnt);
      }
      cnt+=1;
    }
  }
  return 0;
}
