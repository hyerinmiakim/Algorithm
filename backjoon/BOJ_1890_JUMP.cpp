#include <stdio.h>
#include <iostream>
using namespace std;

int arr[100][100];
long long dp[100][100];
int main()
{
        int N = 0;  
        cin >> N;

        for(int j = 0; j < N; j++)
                for(int k = 0; k < N; k++)
                        cin >> arr[j][k];
	
	    dp[0][0] = 1;
        for(int j = 0; j < N; j++)
        {   
                for(int k = 0; k < N; k++)
                {   
					if(dp[j][k] == 0 || (j == N-1 && k == N-1))
						continue;
                    int dwn = arr[j][k] + j;
                    int rght = arr[j][k] + k;
					if (dwn < N) dp[dwn][k] += dp[j][k];
					if (rght < N) dp[j][rght] += dp[j][k];

                } 
        }   
	 cout << dp[N-1][N-1] << endl;

	return 0;
}