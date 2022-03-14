#include <iostream>
using namespace std;

int T;
int n;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    int dp[11] = {};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i=4; i<=11; i++) {
        dp[i] = dp[i-1]  + dp[i-2] + dp[i-3];
    }
    while(T--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}