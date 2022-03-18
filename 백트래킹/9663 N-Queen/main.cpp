#include <iostream>
#include <vector>

using namespace std;
#define Y first
#define X second

int board[16][16];
bool vis[16][16];
vector<pair<int,int>> arr(16);
int ret;
int N;
bool is_attack(int y, int x) {
    for(int i=0; i<N; i++) {
        auto qu = arr[i];
        if(!vis[qu.Y][qu.X]) continue;
        if(y == qu.Y || x == qu.X || abs(y - qu.Y) == abs(x - qu.X)) {
            return true;
        }
    }
    return false;
}
void func(int cnt) {
    if(cnt == N) {
        ret++;
        return;
    }

    for(int j=0; j<N; j++) {
        if(vis[cnt][j]) continue;
        if(is_attack(cnt,j)) continue;
        vis[cnt][j] = true;
        arr[cnt] = make_pair(cnt,j);
        func(cnt + 1);
        vis[cnt][j] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    func(0);
    cout << ret;
    return 0;
}