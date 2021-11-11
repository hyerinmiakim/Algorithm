#include <stdio.h>
using namespace std;

int main(){
  int n;
  scanf("%d", &n);
  int len = (2*n)-1;
  for(int i = 0; i < n; i++) {
#if 0
    for(int j = 0; j < len; j++) {
      if(j == len/2- i)
      {
        for(int k = j; k < j + (2*(i+1)-1); k++)
          printf("*");
        break;
      }
      else printf(" ");  
    }
    printf("\n");


    for(int j = 0; j < n - (i+1); j++) {
      printf(" ");
    }
    for(int j = 0; j < (2*(i+1)-1); j++) {
      printf("*");
    }
    printf("\n");
#else 
    for(int j = 0; j < len; j++) {
      if (j >= n + i)  break;
      if(j >= n - (i+1)) printf("*");
      else printf(" ");
    }
    printf("\n");
#endif
  }
  return 0;
}