#include <iostream>
#include <queue>
using namespace std;

int N, K;
int vis[100001];
int dist[100001];

void init_val() {
    cin >> N >> K;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    init_val();
    dist[N] = 0;
    vis[N] = true;
    queue<int> Q;
    Q.push(N);
    
    while(!Q.empty()) {
        int cur = Q.front(); 
        Q.pop();
        if(cur == K) {
            cout << dist[K];
            break;
        }

        if(cur >= 1 && !vis[cur-1]) {
            dist[cur-1] = dist[cur] + 1;
            vis[cur-1] = true;
            Q.push(cur-1);
        }
        
        if(cur + 1 <= 100000 && !vis[cur+1]) {
            dist[cur+1] = dist[cur] + 1;
            vis[cur+1] = true;
            Q.push(cur+1);
        }

        if(2*cur <= 100000 && !vis[cur*2]) {
            dist[cur * 2] = dist[cur] + 1;
            vis[cur * 2] = true;
            Q.push(cur * 2);
        }
    }


    return 0;
}