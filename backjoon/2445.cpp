#include <stdio.h>
using namespace std;

int main(){

  int n;
  scanf("%d", &n);
  int len = (2 * n);
  for(int i = 1; i <= len-1; i++) {
    for(int j = 1; j <= len; j++) {
      if(i <= n) {  //윗부분
        if(j <= i || j > len - i)
          printf("*");
        else printf(" ");
      }
      else {
        if(j < len - (i-1) || j > i)
          printf("*");
        else printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
