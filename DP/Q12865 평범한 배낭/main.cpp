#include <iostream>
using namespace std;

int N, K;
int weight[101];
int values[101];
int dp[101][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;

    for(int i=1; i<=N; i++) {
        cin >> weight[i] >> values[i];
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) {
            dp[i][j] = dp[i-1][j];
            if(j - weight[i] >= 0) {
                dp[i][j] = max(dp[i-1][j-weight[i]] + values[i], dp[i-1][j]);
            }
        }
    }

    cout << dp[N][K];
    return 0;
}