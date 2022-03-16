#include <iostream>
using namespace std;
typedef long long ll;
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    cin >> t;
    while(t--) {
        int n = 0;
        cin >> n;
        ll candi = 1;
        for(int i=2; i<=n; i++) {
            candi = candi * i;
            if(i % 5 == 0) {
                int tmp = i;
                while(tmp % 5 == 0) {
                    candi /= 10;
                    tmp /= 5;
                }
            }
            candi = candi % 100000000000000; // 1의 자리를 구하는 데에는 너무 많은 자리수는 필요없으므로 오버플로우를 막기 위해서 나눠준다.
        }
        // candi 의 1의자리 수만 구해주면 된다.
        cout << candi % 10 << '\n';
    }

    return 0;
}