#include <iostream>

#define min(a,b) (a<b ? a:b)
using namespace std;

int dp[30001]; /* dp : 주어진 연산식으로 x가 1이 될 수 있는 최소의 연산식 */
int x;

int main()
{
    cin >> x;
    /* 
    "min(약수들의 횟수 중 최솟값) + 1"
    i 가 1이 되기 위해 필요한 연산횟수
    0, 1 은 고려하지 않는다.
    */
    for(int i = 2; i <=x; i++)
    {
        /* case 1: 1을 빼는 경우*/
        dp[i] = dp[i-1]+1;

        if(i % 2 == 0)
            dp[i] = min (dp[i], dp[i/2] + 1);

        if(i % 3 == 0)
            dp[i] = min (dp[i], dp[i/3] + 1);
        
        if(i % 5 == 0)
            dp[i] = min (dp[i], dp[i/5] + 1);
    }   
    cout << dp[x] << endl;

    return 0; 

}