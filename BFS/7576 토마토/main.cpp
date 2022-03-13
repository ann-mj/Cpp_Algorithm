
// 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다.
// 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미

// 자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다.
// 단, 2 ≤ M,N ≤ 1,000
//  정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸

// 여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력
//  저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을
#include <iostream>
#include <queue>
using namespace std;

#define Y first
#define X second

int M, N; // 가로 , 세로
int board[1001][1001];
int vis[1001][1001];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int not_eatable_tomato = 0;
bool is_continue;
int during_day; // 익는데 걸리는 날짜

void bfs(int n, int m)
{
    queue<pair<int, int>> Q;
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if (board[y][x] == 1)
            {
                vis[y][x] = during_day;
                Q.push({y, x});
            }
        }
    }

    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int ny = cur.Y + dy[dir];
            int nx = cur.X + dx[dir];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (vis[ny][nx] >= 0)
                continue;
            if (board[ny][nx] == -1)
                continue;
            if (board[ny][nx] == 1)
                continue;
            if (board[ny][nx] == 0)
            {
                is_continue = true;
                board[ny][nx] = 1;
                not_eatable_tomato--;
                vis[ny][nx] = vis[cur.Y][cur.X] + 1;
                Q.push({ny, nx});
                during_day = max(during_day, vis[ny][nx]);
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> N;

    for (int y = 0; y < N; y++) {
        fill(vis[y], vis[y] + M, -1); // 0부터 M-1 까지 -1로 채운다.
    }

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 0)
            {
                not_eatable_tomato++; // 아직 안익은 토마토들
            }
        }
    }

    // 1인 토마토 주변 익히자
    bfs(N, M);

    if (not_eatable_tomato == 0) {
        cout << during_day;
    } else {
        // 모두 익지 못하는 상황
        cout << -1;
    }
    return 0;
}
