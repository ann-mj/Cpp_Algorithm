#include <iostream>

using namespace std;

int M;
int N;

// 선택한 숫자들이 담길 배열. M 개 까지 될 수 있음
int arr[10]; 
// 중복 체크
bool vis[10];

void func(int cnt) {
    if(cnt == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    // 1부터 N 까지
    for(int i=1; i<=N; i++) {
        if(vis[i]) continue;
        vis[i] = true;
        arr[cnt] = i;
        func(cnt+1);
        vis[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int num[10];
    for(int i=1; i<10; i++) {
        num[i] = i;
    }

    func(0);
    return 0;
}