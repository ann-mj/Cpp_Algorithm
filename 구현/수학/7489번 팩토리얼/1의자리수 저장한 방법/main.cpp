// 25 * 6 , 25 * 16 을 보면 무조건 최우측 0이아닌 수가 일의자리 수만 저장해서는 안되는것을 알 수 있다.!

#include <iostream>
using namespace std;
typedef long long ll;

int fact[1002];
int factorial(int n) {
    if(fact[n] != 0) {
        return fact[n];
    }
    if(n == 0 || n == 1) {
        fact[n] = 1;
    } else {
        int result = n * factorial(n-1);
        while(result != 0) {
            int r = result % 10;
            if(r == 0) {
                result /= 10;
            } else {
                fact[n] = r;
                break;
            }
        }
    }
    return fact[n];
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 0;
    cin >> t;
    while(t--) {
        int n = 0;
        cin >> n;
        // 최우측 0이 아닌 수 구하기
        int result = factorial(n);
        while(result != 0) {
            int r = result % 10;
            if(r == 0) {
                result /= 10;
            } else {
                cout << r << '\n';
                break;
            }
        }
    }
    return 0;
}