#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int V,E;
    cin >> V >> E;

    int start_node = 0;
    cin >> start_node;

    vector<pair<int,int>> adj[20001];

    for(int i=0; i<E; i++) {
        int from = 0;
        int to = 0;
        int co = 0;
        cin >> from >> to >> co;
        adj[from].push_back({to,co});
    }

    int max_value = (int) 1e9;

    int dist[20001];
    int pre[20001];
    for(int i=0; i<=20000; i++) {
        dist[i] = max_value;
    }
    dist[start_node] = 0;

    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    pq.push({dist[start_node], start_node});
    pre[start_node] = 0;

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int c_idx = cur.second;
        int c_dist = cur.first;
        if(dist[c_idx] != c_dist) continue;
        for(auto nxt : adj[c_idx]) {
            int n_idx = nxt.first;
            int n_dist = nxt.second;
            if(dist[n_idx] > n_dist + dist[c_idx]) {
                dist[n_idx] = n_dist + dist[c_idx];
                pre[n_idx] = c_idx;
                pq.push({dist[n_idx], n_idx});
            }
        }
    }
    // 경로 출력
    // for(int i=1; i<=V; i++) {
    //     cout << i << " : ";
    //     if(pre[i] == 0) {
    //         if(i == start_node) {
    //             cout << "자기 자신" << '\n';
    //         } else {
    //             cout << "경로 없음" << '\n';

    //         }
    //     } else {
    //         int prev = pre[i];
    //         while(prev != 0) {
    //             cout << prev << ' ';
    //             prev = pre[prev];
    //         }
    //         cout << '\n';
    //     }
    // }
    // cout << '\n';

    for(int i=1; i<=V; i++) {
        if(dist[i] == (int) 1e9) {
            cout << "INF" << '\n';
        } else {
            cout << dist[i] << '\n';
        }
    }

    return 0;
}