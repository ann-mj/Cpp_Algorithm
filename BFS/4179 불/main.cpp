/*
지훈이와 불은 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동한다. 
불은 각 지점에서 네 방향으로 확산된다. 
지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다. 
지훈이와 불은 벽이 있는 공간은 통과하지 못한다.
J는 입력에서 하나만 주어진다.

지훈이가 불이 도달하기 전에 미로를 탈출 할 수 없는 경우 IMPOSSIBLE 을 출력한다.
*/
#include <iostream>
#include <queue>
using namespace std;

#define Y first
#define X second

int R, C;
char board[1001][1001];
int ret = (int) 1e9; // 가장 짧은 탈출시간
int time_fire[1001][1001];
int time_jh[1001][1001];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
bool is_escape;
int main() {
    // 1,1 부터 시작할거임
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C;  // R : y, C : x

    pair<int,int> jihoon;
    for(int y=1; y<=R; y++) {
        string s;
        cin >> s;
        for(int x=1; x<=C; x++) {
            board[y][x] = s[x-1];

            // 시작점
            if(board[y][x] == 'J') {
                jihoon.Y = y;
                jihoon.X = x;
            }
        }
    }

    for(int y=1; y<=R; y++) {
        fill(time_fire[y] + 1, time_fire[y] + C + 1, -1);
        fill(time_jh[y] + 1, time_jh[y] + C + 1, -1);
    }

    // 불 확산 : time_fire 이 1이면, 해당 위치에 1분 뒤에 불이 확산된다는 뜻.
    queue<pair<int,int>> Q_fire;
    for(int y=1; y<= R; y++) {
        for(int x=1; x<= C; x++) {
            if(board[y][x] == 'F') {
                time_fire[y][x] = 0; // 처음 불의 위치를 0으로 초기화 해준다.
                Q_fire.push({y,x});
            }
        }
    }
    while(!Q_fire.empty()) {
        pair<int,int> fire = Q_fire.front(); Q_fire.pop();
        for(int i=0; i<4; i++) {
            int ny = fire.Y + dy[i];
            int nx = fire.X + dx[i];
            if(ny < 1 || ny > R || nx < 1 || nx > C) continue;
            if(board[ny][nx] == '#') continue;
            if(time_fire[ny][nx] >= 0) continue;
            time_fire[ny][nx] = time_fire[fire.Y][fire.X] + 1;
            Q_fire.push({ny,nx});
        }
    }

    // 지훈이 이동
    queue<pair<int,int>> Q_jh;
    time_jh[jihoon.Y][jihoon.X] = 0;
    Q_jh.push({jihoon.Y, jihoon.X});

    while (!Q_jh.empty()) {
        pair<int,int> jh = Q_jh.front(); Q_jh.pop();
        if(jh.Y == 1 || jh.Y == R || jh.X == 1 || jh.X== C) {
            is_escape = true;
            ret = min(ret,time_jh[jh.Y][jh.X]);
        } 
        for(int i=0; i<4; i++) {
            int ny = jh.Y + dy[i];
            int nx = jh.X + dx[i];
            if(ny < 1 || ny > R || nx < 1 || nx > C) continue;
            if(board[ny][nx] == '#') continue;
            if(time_jh[ny][nx] >= 0) continue;
            //TODO time_fire[ny][nx] != -1 이부분을 고려하지 못했다..
            if(time_fire[ny][nx] != -1 && time_fire[ny][nx] <= time_jh[jh.Y][jh.X] + 1) continue; // 다음에 이동할 칸이 이미 불이 난 칸이라면 패스
            time_jh[ny][nx] = time_jh[jh.Y][jh.X] + 1;
            Q_jh.push({ny,nx});
        }
    }

    if(!is_escape) {
        // 탈출할 수 없는 경우(지훈이가 이동할 수 없는 경우)
        cout << "IMPOSSIBLE";
    } else{
        cout << ret + 1; // 마지막 칸에서 한번 더 가야 벗어날 수 있음.
    }
    return 0;
}



/*
1. ny , nx 변수 잘못 적었다.
2. BFS 도는 부분 안에서, cur 라고 표현을 해주자. jh, fire 등의 변수를 쓰니까 헷갈려서 문제가 생겼다.
3. 불이 이동하지 못하는 경우를 고려하지 못했다.
4 4
###F
#J.#
#..#
#..#


*/