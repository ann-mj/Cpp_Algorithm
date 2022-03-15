// 양의 정수 n이 주어졌을 때, 이를 이진수로 나타냈을 때
// 1의 위치를 모두 찾는 프로그램을 작성하시오. 최하위 비트(least significant bit, lsb)의 위치는 0이다.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T, N;
string answer;
void to_binary(int N) {
    vector<char> result;
    while(N != 1) {
        int q = N / 2;
        int r = N % 2;
        N = q;
        if(q == 1) {
            result.push_back(r+'0');
            result.push_back(q+'0');
        } else {
            result.push_back(r+'0');
        }
    }
    while(result.size() > 0) {
        answer.push_back(result.back());
        result.pop_back();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> N;
        answer = "";
        if(N == 1) {
            cout << 0 << '\n';
            continue;
        }
        to_binary(N);
        for(int i=answer.length()-1; i>=0; i--) {
            if(answer[i] == '1') {
                cout << answer.length() - 1 - i << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}