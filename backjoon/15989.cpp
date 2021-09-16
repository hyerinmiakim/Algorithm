#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int N = 0, Num;
  vector<int> numb;
  cin >> N;

  for (int i = 0; i < N; i++)
  {
    cin >> Num;
    vector<int> dp(10001, 0);
    dp[0] = 1;
    for (int i = 1; i <= 3; i++) {
      for (int j = i; j <= Num; j++) {
        dp[j] += dp[j - i];
      }
    }
    numb.push_back(dp[Num]);
  }
  for (int i : numb) cout << i <<endl;
  return 0;
}