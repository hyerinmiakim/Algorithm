#include <iostream>
#include <vector>
#define min(a, b) (a < b ? a : b)
using namespace std;

int main()
{
    int n, m;
    vector<int> cash (101, 0);
    vector<int> money (101, 10001);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> cash[i];

    money[0] = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = cash[i];
        for(int j = tmp; j <= m; j++)
        {
#if 0 /* my code */
            if(tmp == j)
            {
                money[j] = 1;
                continue;
            }
#else
            if(money[j - tmp] != 10001)
#endif
            money[j] = min(money[j-tmp]+1, money[j]);
        }
    }
    if(money[m] >= 10001)
        money[m] = -1;
    printf("answer: %d\n", money[m]);

    return 0; 

}