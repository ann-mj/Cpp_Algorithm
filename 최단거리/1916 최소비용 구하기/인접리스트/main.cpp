#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    // first : 정점 번호 , second : 비용
    vector<pair<int,int>> adj[1001];
    
    for(int i=0; i<M; i++) {
        int from;
        int to;
        int co;
        cin >> from >> to >> co;
        adj[from].push_back({to,co});
    }

    int start_city = 0;
    int end_city = 0;
    cin >> start_city >> end_city;

    // dist 배열
    int dist[1001];
    for(int i=0; i<=1000; i++) {
        dist[i] = (int) 1e9;
    }
    dist[start_city] = 0; // 시작점 거리 초기화

    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;

    // 거리, 좌표 
    pq.push({dist[start_city], start_city});
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int idx = cur.second;
        int d = cur.first;
        
        // 더 작은 cost에 대해 처리완료
        if(dist[idx] != d) continue; 

        // 인접노드 탐색
        for(auto nxt : adj[idx]) {
            int n_idx = nxt.first;
            int n_co = nxt.second;
            if(dist[n_idx] > dist[idx] + n_co) {
                dist[n_idx] = dist[idx] + n_co;
                pq.push({dist[n_idx], n_idx});
            }
        }
    }
    cout << dist[end_city];
    return 0;
}