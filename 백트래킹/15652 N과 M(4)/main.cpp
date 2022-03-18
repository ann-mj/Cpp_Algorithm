#include <iostream>

using namespace std;

int N, M;
int arr[9];

void func(int cnt) {
    if(cnt == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++) {
        if(cnt > 0 && arr[cnt-1] > i) continue;
        arr[cnt] = i;
        func(cnt+1);
    }
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    func(0);
    return 0;
}