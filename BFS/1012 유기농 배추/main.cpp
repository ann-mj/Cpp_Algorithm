#include <iostream>
#include <queue>
using namespace std;
#define Y first
#define X second

int T;
int M, N, K;
int ret;
int board[50][50];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void init_val() {
    ret = 0;
    cin >> M >> N >> K;
    for(int i=0; i<50; i++) {
        fill(board[i] , board[i] + 50, 0);
    }

    for(int i=0; i<K; i++) {
        int x;
        int y;
        cin >> x >> y;
        board[y][x] = 1;
    }
}

void solve() {
    int ans = 0;
    bool vis[50][50] = {};
    for(int y=0; y<N; y++) {
        for(int x=0; x<M; x++) {
            if(vis[y][x]) continue;
            if(board[y][x] == 0) continue;
            queue<pair<int,int>> Q;
            vis[y][x] = true;
            Q.push({y,x});
            while(!Q.empty()) {
                pair<int,int> cur = Q.front(); Q.pop();
                for(int i=0; i<4; i++) {
                    int ny = cur.Y + dy[i];
                    int nx = cur.X + dx[i];
                    if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
                    if(vis[ny][nx]) continue;
                    if(board[ny][nx] == 0) continue;
                    vis[ny][nx] = true;
                    Q.push({ny,nx});
                }
            }
            ans++;
        }
    }

    ret = ans;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--) {
        init_val();
        solve();
        cout << ret << '\n';
    }

    return 0;
}