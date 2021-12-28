#include <stdio.h>
using namespace std;

int main(){
  int n, m;
  int arr[10001];
  
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int left=0, right=0, sum = 0, answer = 0;
  while(right <= n) {
    // right 증가
    if(sum < m) {
      sum += arr[right];
      right += 1;
    }
    
    else if (sum >= m) {
      sum -= arr[left];
      left+=1;
    }

    if(sum == m) 
      answer+=1;
  }

  printf("%d\n", answer);
  return 0;
}