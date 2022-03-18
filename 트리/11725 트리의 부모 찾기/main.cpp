#include <iostream>
#include <vector>

using namespace std;

int p[100001]; // p[1] 은 1의 부모
vector<int> arr[100001];
int N;

void put_parent(int cur) {
    for(auto adj : arr[cur]) {
        if(p[adj] != 0) continue; // 이게 제일 중요하네 -> 이거 없으면 무한 루프에 걸림
        p[adj] = cur;
        put_parent(adj);
    }
}

int main(void) {
    cin >> N;

    for(int i=0; i<N-1; i++) {
        int from;
        int to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }

    put_parent(1);

    for(int i=2; i<=N; i++) {
        cout << p[i] << '\n';
    }
    return 0;
}