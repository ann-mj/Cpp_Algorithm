#include <string>
#include <vector>
#include <queue>

#define Y first
#define X second

using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool visit[201];

void bfs(int n, int idx, vector<vector<int>> computers) {
    visit[idx] = true;
    queue<int> q;
    q.push(idx);
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i=0; i<n; i++) {
            if(computers[cur][i] == 0) continue;
            if(i == cur) continue;
            if(visit[i]) continue;
            visit[i] = true;
            q.push(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++) {
        if(visit[i]) continue;
        bfs(n, i, computers);
        answer++;
    }
    return answer;
}