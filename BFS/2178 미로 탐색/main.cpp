#include <iostream>
#include <queue>
using namespace std;

#define Y first
#define X second

int N, M;
int ret; // 최단거리

// int arr[101][101]; 이렇게만 해도 되나??
// int 로는 어떻게 입력을 받지?
char board[101][101];
int dist[101][101];

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int y = 1; y <= N; y++)
    {
        string s;
        cin >> s;
        for (int x = 1; x <= M; x++)
        {
            board[y][x] = s[x - 1];
        }
    }

    for (int y = 1; y <= N; y++)
    {
        // fill 은 어디에 있지? 어떻게 사용하지? ,
        // 처음 시작점 포함 ,  두번 째 점 미포함
        fill(dist[y], dist[y] + M + 1, -1);
    }

    // 시작점
    dist[1][1] = 1;
    queue<pair<int, int>> Q;
    Q.push({1, 1});

    // 방문 여부 체크는 dist 가 -1 인지를 통해서 확인한다.
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        if (cur.Y == N && cur.X == M)
        {
            ret = dist[cur.Y][cur.X];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = cur.Y + dy[i];
            int nx = cur.X + dx[i];
            if (ny < 1 || ny > N || nx < 1 || nx > M)
                continue;
            if (dist[ny][nx] != -1)
                continue; // 이미 방문한 노드
            if (board[ny][nx] == '0')
                continue; // 이동할 수 없는 칸
            dist[ny][nx] = dist[cur.Y][cur.X] + 1;
            Q.push({ny, nx});
        }
    }
    cout << ret;
    return 0;
}