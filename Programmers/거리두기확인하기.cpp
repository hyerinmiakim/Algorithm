#include <string>
#include <vector>
#include <queue>

using namespace std;

int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<string> board;

bool bfs(int x, int y) {
    queue<pair<int, int> > que;
    que.push({x, y});
    while(!que.empty()) {
        int px = que.front().first;
        int py = que.front().second;
        que.pop();
        for(int j = 0; j < 4; j++) {
            int cx = px + pos[j][0];
            int cy = py + pos[j][1];
            int dist = abs(cx - x) + abs(cy - y);
            
            if(cx >= 5 || cy >= 5 || cx < 0 || cy < 0 || (cx == x && cy == y)) continue;
            if(board[cx][cy] == 'P' && dist <= 2) return false;
            if(board[cx][cy] == 'O' && dist < 2) que.push({cx, cy});
        }
    }
    
    return true;
}

bool checkDistance(vector<string> vec) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            if(vec[i][j] == 'P') {
                if(!bfs(i, j)) return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(auto s : places) {
        board = s;
        answer.push_back(checkDistance(s));
    }
    return answer;
}