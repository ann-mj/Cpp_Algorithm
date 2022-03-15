#include <iostream>
#include <vector>
using namespace std;

int N;
int target;
int mid_y, mid_x;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int board[1000][1000];
int dist; // 중심으로 부터의 거리
class snail {
    public:
    int y;
    int x;
    int val = 1;
    int d = 0;
    
    snail(int sy, int sx, int sd) {
        y = sy;
        x = sx;
        d = sd;
    }
    
    void move() {
        int ny = 0;
        int nx = 0;
        while(true) {
            bool is_dir = false;
            int num = board[y][x];
            for(int i=1; i<=N; i+=2) {
                if(num == i*i) {
                    is_dir = true; // 제곱수 는 방향 안바꾼다.
                    break;
                }
            }
            ny = y + dy[d];
            nx = x + dx[d];
            if(is_dir) {
                // 방향 그대로, 제곱 수 인경우
                if(ny == 0 || ny == N+1 || nx == 0 || nx == N+1) return;
                dist++;
                y = ny;
                x = nx;
                val++;
                board[y][x] = val;
            } else {
                if(ny < mid_y - dist || ny > mid_y + dist
                || nx < mid_x - dist || nx > mid_x + dist) {
                    // 방향을 바꾼다.
                    d = (d+1) % 4;
                }
                ny = y + dy[d];
                nx = x + dx[d];
                y = ny;
                x = nx;
                val++;
                board[y][x] = val;
            }
        }
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> target;
    mid_y = (N+1)/2;
    mid_x = (N+1)/2;
    snail s(mid_y, mid_x, 0);
    board[mid_y][mid_x] = 1;
    s.move();
    int ty = 0;
    int tx = 0;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(board[i][j] == target) {
                ty = i;
                tx = j;
            }
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }

    cout << ty << ' ' << tx;
    
    return 0;
}