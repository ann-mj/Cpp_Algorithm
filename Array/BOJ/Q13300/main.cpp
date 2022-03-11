#include <iostream>
using namespace std;

int N, K;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    //학생 배열
    int arr[7][2] = {};

    for(int i=0; i<N; i++) {
        int S = 0;
        int Y = 0;
        cin >> S >> Y;
        if(S == 0) {
            arr[Y][0]++;
        } else {
            arr[Y][1]++;
        }
    }

    int room = 0;
    for(int i=1; i<=6; i++) {
        for(int j=0; j<2; j++) {
            if(arr[i][j] == 0) continue;
            room += ((arr[i][j])/K);  // 몫
            if(((arr[i][j]) % K)) {  // 나머지
                room++;
            }
        }
    }

    ret = room;
    cout << ret;
    return 0;
}