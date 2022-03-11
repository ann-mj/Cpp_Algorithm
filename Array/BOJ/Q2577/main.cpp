#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int result;

    int A, B, C;
    cin >> A >> B >> C;

    result = A * B * C;

    // int -> string ?

    // int 자리수 구하기
    int nums[10] = {};
    while(result > 0) {
        nums[result % 10]++;
        result /= 10;
    }

    for(int e : nums) {
        cout << e << '\n';
    }
    
    return 0;
}