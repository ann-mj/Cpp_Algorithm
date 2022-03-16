#include <iostream>
using namespace std;

int factors[100001];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int M = 0;
    int N = 0;
    cin >> M >> N;
    for(int i=2; i<=100000; i++) {
        factors[i] = i;
    }

    for(int i=2; i*i<=100000; i++) {
        for(int j = i; j<=100000; j+=i) {
            if(factors[j] == j) {
                factors[j] = i;
            }
        }
    }
    int sum = 0; // 소수의 합
    int val = 0; // 최소값
    bool is_found = false;
    for(int i=M; i<=N; i++) {
        if(factors[i] == i) {
            is_found = true;
            sum += i;
            if(val == 0) {
                val = i;
            }
        }
    }
    
    if(!is_found) {
        cout << -1;
    } else {
        cout << sum << '\n' << val;
    }
    return 0;
}