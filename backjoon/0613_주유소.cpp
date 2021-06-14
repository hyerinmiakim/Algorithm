#include <stdlib.h>
#include <iostream>
using namespace std;

int dist[100000];
int cost[100000];

int main(void)
{
    int n;
    long long total = 0;
    long long pay = 0;

    scanf("%d", &n);

    for (int i = 1; i < n; i++)
        scanf("%d", &dist[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &cost[i]);

    pay = cost[0];
    total = pay * dist[1];
    for (int i = 1; i < n; i++)
    {
        if (pay < cost[i])
        {
            total += pay * dist[i + 1];
        }
        else
        {
            pay = cost[i];
            total += pay * dist[i + 1];
        }
    }

    printf("%lld\n", total);
    return 0;
}