#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visit[1001];
vector<vector<int> > a (1001, vector<int> (1001, 0));
int N, M, S;

void bfs(int start) 
{
	queue<int> que;
	que.push(start);
	visit[start] = true; // visit배열의 1번째에 set
    
  while (!que.empty()) {
		int x = que.front();
		que.pop();
    printf("%d ", x);
		for (int i = 1; i <= N; i++) {
      if (!visit[i] && a[x][i] == 1) {
				que.push(i);
				visit[i] = true;
			}
		}
	}
}

void dfs(int start)
{
	printf("%d ", start);

	for (int i = 1; i <= N; i++) {
		if (a[start][i] == 1 && !visit[i])
		{
			visit[i] = 1;
			dfs(i);
		}
	}
}

int main(void) {

  int h1, h2;
  scanf("%d%d%d", &N, &M, &S);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &h1, &h2);
		a[h1][h2]=1;
		a[h2][h1]=1;
	}

  visit[S] = 1;
	dfs(S); 
  printf("\n");
  
	memset(visit, 0, sizeof(visit)); //dfs에서 visit을 썼기 때문에 초기화 해줌
  bfs(S);
	
	return 0;
}