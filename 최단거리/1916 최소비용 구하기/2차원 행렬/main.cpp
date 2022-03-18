// 5
// 10
// 1 2 2
// 1 2 3
// 1 2 1
// 1 3 3
// 1 4 1
// 1 5 10
// 2 4 2
// 3 4 1
// 3 5 1
// 4 5 3
// 1 4

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int M;

int board[1001][1001];

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for(int i=0; i<=N; i++) {
        for(int j=0; j<=N; j++) {
            board[i][j] = 1000000000;
        }
    }

    for(int i=0; i<M; i++) {        
        int from = 0;
        int to = 0;
        int d = 0;
        cin >> from >> to >> d;
        board[from][to] = min(board[from][to], d);
    }

    int first = 0;
    int second = 0;
    cin >> first >> second; // first -> second  최단거리

    // 시작점은 0, 나머지는 INF 로 초기화를 시킨다.
    int dist[N+1];
    for(int i=0; i<=N; i++) {
        dist[i] = 1000000000;
    }
    dist[first] = 0;


    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    pq.push({dist[first],first});

    while(!pq.empty()) {
        pair<int,int> cur = pq.top(); pq.pop();
        int index = cur.second;
        int distance = cur.first;
        if(dist[index] != distance) continue;
        for(int i=1; i<=N; i++) {
            if(distance + board[index][i] < dist[i]) {
                dist[i] = distance + board[index][i];
                pq.push({dist[i], i});
            }
        }
    }

    cout << dist[second];
    
    return 0;
}