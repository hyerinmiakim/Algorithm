#include <iostream>
using namespace std;
int dp[1001]; // dp[n] : 자기 안에 들어가 있는 상자 수
int box[1001];

int main() {
  int n, cnt = 0;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> box[i];
    dp[i] = 1;
  }
  // dp: 현재까지(i) 최대로 만들 수 잇는 상자의 수를 세어주는 배열
  for(int i = 1; i <= n; i++) {
    for(int j = i-1; j >= 0; j--) { //자신 보다 아래에 있는 애들 중 작은 애들을 모두 탐색
      if(box[i] > box[j]) {
        if(dp[i] <= dp[j])  // 만약 내가 가지고 있는 상자랑 걔가 가지고 있는 상자수가 같거나 크면,
        {
            dp[i] = dp[j] + 1; // +1한 값을 저장함
        }
      }
    }
    if(cnt < dp[i]) cnt = dp[i];
  }
  cout << cnt << endl;
  return 0;
}