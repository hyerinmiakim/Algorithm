#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;

void backtracking(int sum, int num, int oper, string str, int depth) {
  if(depth == N) {
    sum += (oper * num);
    if(sum == 0) cout << str << "\n";
    return;
  }
  // ascii 순서대로 호출
  depth += 1;
  backtracking(sum, (num*10) + depth, oper, str + ' ' + to_string(depth), depth);
  backtracking(sum + (oper * num), depth, 1, str + '+' + to_string(depth), depth);
  backtracking(sum + (oper * num), depth, -1, str + '-' + to_string(depth), depth);
  depth -= 1;
}

int main(){
  int T;
  cin >> T;
  while(T--) {
    cin >> N;
    backtracking(0, 1, 1, "1", 1);
    cout << "\n";
  }
  return 0;
}
