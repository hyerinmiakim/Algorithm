#include <stdio.h>
using namespace std;

int num[1001];
int main(){
  int n, mx = 0;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d", &num[i]);
    if(mx < num[i]) mx = num[i];
  }
  double avg, total = 0;
  for(int i = 0; i < n; i++) {
    float idx = (double) num[i] / (double)mx * 100;
    total += idx;
  }
  printf("%.2f", total/n);
  return 0;
}
