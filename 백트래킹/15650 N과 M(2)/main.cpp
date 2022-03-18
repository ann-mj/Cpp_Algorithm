#include <iostream>

using namespace std;

int N, M;
int arr[9]; // 고른 숫자
bool vis[9]; // 담겼는지 안담겼는지

void func(int cnt) {
    if(cnt == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        if(cnt > 0 && arr[cnt-1] > i) {
            continue;
        }
        vis[i] = true;
        arr[cnt] = i;
        func(cnt+1);
        vis[i] = false;
    }
}

int main(void) {
    cin >> N >> M;
    func(0);
    return 0;
}