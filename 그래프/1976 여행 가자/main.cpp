#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> adj[201];
int par[201];

int find_parent(int x) {
    if(par[x] != x) {
        par[x] = find_parent(par[x]);
    }
    return par[x];
}

void union_parent(int a, int b) {
    a = find_parent(a);
    b = find_parent(b);

    if(a < b) {
        par[b] = a;
    } else {
        par[a] = b;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N;
    int M;
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int v = j;
            cin >> v;
            if(v == 0) continue;
            adj[i].push_back(j);    
            adj[j].push_back(i);    
        }
    }

    vector<int> todo;
    for(int i=0; i<M; i++) {
        int v;
        cin >> v;
        todo.push_back(v);
    }

    for(int i=1; i<=N; i++) {
        par[i] = i;
    }

    for(int i=1; i<=N; i++) {
        for(int a : adj[i]) {
            union_parent(i,a);
        }
    }
    if(M == 2) {
        int pre = todo[0];
        int cur = todo[1];
        
        if(find_parent(pre) != find_parent(cur)) {
            cout << "NO";
            return 0;
        }
    }
    for(int i=2; i<M; i++) {
        int pre = todo[i-1];
        int cur = todo[i];
        
        if(find_parent(pre) == find_parent(cur)) continue;
        cout << "NO";
        return 0;
    }
    // todo 를 보면서, i 가 i-1 의 부모이면 됨.
    // root 를 1로 union find 해보자
    cout << "YES";
    return 0;
}
