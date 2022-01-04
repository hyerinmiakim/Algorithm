#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
vector<int> answer;

bool isCorrectWithN(int target) {
  int sum = 0;
  while(target/10 > 0) {
    sum += (target % 10);
    target /= 10;
  }
  sum += target;
  if(sum == n) return true;
  return false;
}

void backtrack(int idx, int num) {  // 문자열에 들어갈 수, 더한 수
  if(num >= n) {
    if(isCorrectWithN(idx))
        answer.push_back(idx);
    return;
  }
  
  for(int i = 1; i <= 3; i++) {
    num += i;
    backtrack(idx*10 + i, num);
    num -= i;
  }
}

int main(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++) {
    backtrack(i,i);
  }

  if(answer.size() < k) 
    cout << "-1\n";
  else {
    string t = to_string(answer[k-1]);
    int len = t.size();
    for(int i = 0; i < len-1; i++)
      cout << t[i] << "+";
    
  cout << t[len-1];
  }

  return 0;
}
