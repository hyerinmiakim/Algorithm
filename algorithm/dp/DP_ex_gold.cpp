#include <iostream>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int main()
{
    int t = 0; 
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n, m, result = 0;
        cin >> n >> m;

        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= m; k++)
                cin >> arr[j][k];

        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= m; k++)
                dp[j][k] = arr[j][k];

        for(int j = 1; j <= n; j++)
       {
          for(int k = 1; k <= m; k++)
            {
                //printf("%d ", arr[j][k]);
                int t = max(dp[j][k-1], max(dp[j-1][k-1],dp[j+1][k-1]));
                dp[j][k] = arr[j][k] + t;
                printf("%d + %d = %d\n", arr[j][k], t , dp[j][k]);
            }
            printf("--------\n");
       }

        for(int j = 1; j <= n; j++)
            result = max(result, dp[j][m]);

        printf("resu;t: %d\n", result);
    }

   

    return 0;
}