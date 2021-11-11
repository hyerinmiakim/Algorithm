#include <stdio.h>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int len = (2*n) - 1;
  for(int i = 1; i <= len; i++) {
    for(int j = 0; j < len; j++) {
      if(i > n) {
        if(j < i - n) printf(" ");
        else if (j - n + i >= len)  break;
        else printf("*");
      }
      else {
        if (j >= n + (i-1))  break;
        //if (j >= n - i) printf("*");
        //else printf(" ");
        if (j < n - i)  printf(" ");
        else printf("*");
      }
    }
    printf("\n");
  }
  return 0;
}
