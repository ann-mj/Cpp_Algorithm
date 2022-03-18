#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int V, E;

vector<pair<int,int> > adj[10001];
class node {
    public:
    int from;
    int to;
    int dist;

    node(int from, int to, int dist) {
        this->from = from;
        this->to = to;
        this->dist = dist;
    }

    bool operator<(node& o) {
        return dist < o.dist;
    }
};

bool vis[10001];
int cnt; // 간선의 개수
int res; // 가중치의 합
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> V >> E;

    while(E--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        adj[from].push_back({to,dist});
        adj[to].push_back({from,dist});
    }

    // 프림 알고리즘
    // pq 를 보며, 간선 정보를 얻어야 함. 
    // 가중치, 정점 1,2
    priority_queue<tuple<int,int,int>,
                   vector<tuple<int,int,int>>,
                    greater<tuple<int,int,int>>> pq;
    
    vis[1] = true;
    cnt = 1;
    for(auto a : adj[1]) {
        pq.push({a.second,1,a.first});
    }
    
    while(!pq.empty()) {
        int dist, from, to;
        tie(dist, from, to) = pq.top(); pq.pop();
        // 가장 작은 가중치의 간선으로 부터 연결된 노드 체크
        if(cnt == V) break;
        if(vis[to]) continue;
        cnt++;
        res += dist;
        vis[to] = true;

        for(auto edge : adj[to]) {
            if(vis[edge.first]) continue;
            pq.push({edge.second, to, edge.first});
        }
    }
    cout << res ;
    return 0;
}