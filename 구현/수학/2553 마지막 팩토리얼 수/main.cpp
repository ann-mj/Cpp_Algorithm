#include <iostream>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int result = 0;
    if(N==1) {
        cout << 1;
        return 0;
    }
    ll temp = 1; // 곱한 값
    for(int i=2; i<=N; i++) {
        temp = temp * i;
        int multi = i;
        while(multi % 5 == 0) {
            temp /= 10; // 5가 들어가면 0이 하나 생기는데, 이 0을 없애기 위해서 10으로 나눈다.
            multi /= 5;
        }
        temp %= 1000000000000;
    }
    cout << temp % 10;
    return 0;
}