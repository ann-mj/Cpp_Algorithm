#include <iostream>
using namespace std;
int ret;
int input = 0;
int d[10] = {0,}; // 자리수를 구하자.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 6과 9는 뒤집어서 이용 가능
    // 방 번호를 플라스틱 숫자로 붙이려고 함. 
    // 필요한 세트의 개수 ( 0 ~ 9 한세트씩 있음 )

    cin >> input;

    while(input > 0) {
        d[input%10]++;
        input /= 10;
    }
    
    // 최대 값을 찾자. (6이랑 9제외하고)
    int max_value = 0;
    for(int i=0; i<10; i++) {
        if(i == 6 || i == 9) continue;
        max_value = max(max_value, d[i]);
    }
    ret += max_value;

    // 6이랑 9만 보자.
    int sum = d[6] + d[9];
    if(sum > (2*max_value)) {
        ret += (sum - 2*max_value +1)/2;
    }

    cout << ret;
    
    return 0;
}