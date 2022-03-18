#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int ret; // 가중치의 합
int V, E;
    //비용, 간선
vector<pair<int,int>> adj[10001];
bool vis[10001];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> V >> E;
    while(E--) {
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({to,cost});
        adj[to].push_back({from,cost});
    }

                    // to , cost
    priority_queue<pair<int,int>,
                    vector<pair<int,int>>,
                    greater<pair<int,int>>> pq;
    for(auto cur : adj[1]) {
        pq.push({cur.second, cur.first});
    }
    int cnt = 1;
    vis[1] = true;

    while(cnt != V) {
        auto cur = pq.top(); pq.pop();
        int to = cur.second;
        int cost = cur.first;
        if(vis[to]) continue; // 이미 신장트리에 포함되었다면 pass
        cnt++;
        ret += cost;
        vis[to] = true;
        for(auto nxt : adj[to]) {
            if(vis[nxt.first]) continue;
            pq.push({nxt.second, nxt.first});
        }
    }
    cout << ret;
    return 0;   
}