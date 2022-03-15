#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    int candi = x;
    while(x!=0) {
        sum += x%10;
        x = x/10;
    }
    if(candi % sum == 0) return true;
    return false;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a = 10;
    bool answer = solution(a);
    cout << answer;
    return 0;
}