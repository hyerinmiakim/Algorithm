dfdafd
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int visit[1003];
vector<int> a[1003];

void bfs(int start) {
	queue<int> q;
	memset(visit, 0, sizeof(visit)); //dfs에서 visit을 썼기 때문에 초기화 해줌
	q.push(start);
	visit[start] = true; // visit배열의 1번째에 set

	while (!q.empty()) {
		int x = q.front();
		q.pop();
    printf("%d ", x);
		for (int i = 0; i < a[x].size(); i++) {	//뽑아낸 데이터의 트리 수 만큼 for문을 돌리며 탐색	
			int y = a[x][i];
			if (!visit[y]) {
				q.push(y);
				visit[y] = true;
			}
		}
	}

  return;
}

void dfs(int start) {
	if (visit[start]) return;

	visit[start] = true;
	printf("%d ", start);
  
	for (int i = 0; i < a[start].size(); i++) {
		int x = a[start][i];
		dfs(x);
	}

  return;
}

int main(void) {

  int line, num, _start, h1, h2;
  scanf("%d %d %d", &line, &num, &_start);
	for (int i = 0; i < num; i++)
	{
		scanf("%d %d", &h1, &h2);
		a[h1].push_back(h2);
		a[h2].push_back(h1);
	}
    
	dfs(_start); 
  printf("\n");
  bfs(_start);
	
	return 0;
}