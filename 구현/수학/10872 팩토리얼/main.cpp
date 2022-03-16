#include <iostream>
using namespace std;
#define endl '\n'
typedef long long ll;

ll fact[10000001];

ll factorial(int n) {
    if(n == 0 || n == 1) {
        fact[n] = 1;
        return fact[n];
    }
    fact[n] = n * factorial(n-1);
    return fact[n];
}
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    ll result = factorial(N);
    cout << result;
    return 0;
}