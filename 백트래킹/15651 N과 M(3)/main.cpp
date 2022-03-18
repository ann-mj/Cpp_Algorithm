#include <iostream>

using namespace std;

int N, M;

int arr[8];

void func(int cnt) {
    // arr[cnt] 에 뭘 넣을지 결정하고, func(cnt+1) 호출
    if(cnt == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++) {
        arr[cnt] = i;
        func(cnt+1);
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N >> M;
    func(0); 
    return 0;
}