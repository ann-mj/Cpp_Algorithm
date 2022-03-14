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

/**
다음엔 이 방법도 고려해보자.
fill(dist, dist+100001,-1);
dist[n] = 0;
queue<int> Q;
Q.push(n);
while(dist[k] == -1){
    int cur = Q.front(); Q.pop();
    for(int nxt : {cur-1, cur+1, 2*cur}) {
        if(nxt < 0 || nxt > 100000) continue;
        if(dist[nxt] != -1) continue;
        dist[nxt] = dist[cur]+1;
        Q.push(nxt);
    }        
}
 * 
 */