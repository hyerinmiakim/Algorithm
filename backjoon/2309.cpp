#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
// 12:36 - 13:14
int main(){
  int vec[9];
  vector<int> answer;
  int sum = 0;
  for(int i = 0; i < 9; i++)
  {
    scanf("%d", &vec[i]);
    sum += vec[i];
  }

  for(int i = 0; i < 8; i++) {
    for(int j = i + 1; j < 9; j++) {
      if(sum - vec[i] - vec[j] == 100) {
        for(int k = 0; k < 9; k++) {
          if(k != i && k != j) {
            answer.push_back(vec[k]);
          }
        }

        sort(answer.begin(), answer.end());
        for(int a : answer)
          printf("%d\n", a);
        return 0;
      }
    }
  }
  /*
  for(int i = 6; i >= 0; i--) 
  {
    int sum = 0;
    for(int j = 0; j < i; j++) {
      sum += vec[j];
    }
      
    
    int idx = 7 - i;
    for(int j = i; j < 9; j++) {
      int ac = 0;
      for(int k = 0; k < idx; k++){
        ac += vec[j + k];
      }
      if(sum + ac == 100) {
        flag = true;
        for(int k = 0; k < idx; k++){
          answer.push_back(vec[j + k]);
        }
        for(int k = 0; k < i; k++)
          answer.push_back(vec[k]);
        break; 
      }
    }
    if(flag) break;
  }
  sort(answer.begin(), answer.end());
  for(int i : answer)
    printf("%d\n", i);
  */
  
  return 0;
}
