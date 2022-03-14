#include <iostream>

using namespace std;

int N;
int ret;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N; // 최대 1000000 : 100만
    int dp[N+1] = {0,};
    // for(int i=0; i<=N; i++) {
    //     dp[i] = (int)1e9;
    // }

    fill(dp, dp+N+2, (int)1e9);
    dp[N] = 0;
    
    for(int i=N; i>=1; i--) {
        if(i % 3 == 0) {
            dp[i/3] = min(dp[i/3], dp[i] + 1); 
        }

        if(i % 2 == 0) {
            dp[i/2] = min(dp[i/2], dp[i] + 1);
        }

        dp[i-1] = min(dp[i-1], dp[i] + 1);
    }
    cout << dp[1];
    return 0;
}