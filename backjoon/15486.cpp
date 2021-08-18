#include <stdio.h>
#include <iostream>
using namespace std;
#define max(a,b) (a > b ? a : b)

int dp[1500002];
int day[1500002];
int cost[1500002];

int main()
{
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i++)
        cin >> day[i] >> cost[i];

    for(int i = n; i >= 1; i--)
    {
        if(day[i] + i > n+1)
        {
            dp[i] = dp[i+1];
        }
        else
        {
            dp[i] = max (dp[i+1], cost[i] + dp[i + day[i]]);
        }

    }
    cout << dp[1];
    return 0;
}