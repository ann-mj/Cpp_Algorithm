#include <iostream>
using namespace std;
#define endl '\n'
typedef long long ll;

ll fact[50];

ll factorial(int n) {
    if(n == 0 || n == 1) {
        fact[n] = 1;
    } else {
        fact[n] = n * factorial(n-1);
    }
    return fact[n];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    while(1) {
        int N;
        cin >> N;
        if(N == 0) break;

        ll sum = 0; // 이걸 출력해야 한다.
        int ind = 1; // 자리 수
        // 각 N 의 자리수를 구해야 한다.
        while(N != 0) {
            int r = N % 10;
            N /= 10;
            sum += r*factorial(ind);
            ind++;
        }
        cout << sum << endl;    
    }
    
    return 0;
}