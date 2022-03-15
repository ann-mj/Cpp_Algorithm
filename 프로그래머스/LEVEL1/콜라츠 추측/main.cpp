#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = -1;
    long long candi = num;
    int T = 0;
    while(T <= 500) {
        if(candi == 1) {
            answer = T;
            break;
        }
        if(candi % 2 == 0) {
            candi = candi/2;
        } else {
            candi = candi*3 + 1;
        }
        T++;
    }
    
    return answer;
}