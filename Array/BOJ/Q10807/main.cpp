#include <iostream>
using namespace std;
int N;
int v;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    int arr[N] = {0,};

    for(int i=0; i<N;i++) {
        cin >> arr[i];
    }
    cin >> v;

    for(int i=0; i<N; i++) {
        if(arr[i] == v) ret++;
    }

    cout << ret;
    return 0;
}