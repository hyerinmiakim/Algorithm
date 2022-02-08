#include <iostream>
#include <algorithm>
using namespace std;

int n, answer;
char ball[500001];
char color[2] = {'R', 'B'};

int countMovingNum() {
  int answer[2] = {0, };
  for(int c = 0; c < 2; c++) {
    // 현재 색을 왼쪽/오른쪽으로 몰았을 때, 가질 수 있는 최소 이동 횟수 리턴
    char target = color[c];
    bool flag = false;
    // LEFT
    int left = 0;
    for (int i = 0; i < n; i++)
    {
      if (ball[i] == target && flag)
        left += 1;
      
      else if (ball[i] != target && !flag)
        flag = true;
    }

    // RIGHT
    flag = false;
    int right = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      if (ball[i] == target && flag)
        right += 1;

      else if (ball[i] != target && !flag)
        flag = true;
    }

    if(left < right) answer[c] = left;
    else answer[c] = right;
  }

  return min(answer[0], answer[1]);
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  // 다른 색으로 둘러 쌓여있는 현재 색을 발견하면, 다른 색을 발견하기 전까지 이동한다. 

  cin >> n;
  cin >> ball;
  
  cout << countMovingNum();
  return 0;
}
