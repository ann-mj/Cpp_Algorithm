#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    // 중간값 찾아야 함. 이분 탐색
    int L = 0;
    int R = 10000;
    while(L <= R) {
        // 이상 이하 체크
        int mid = (L+R)/2;
        
        int mcnt = 0;
        for(int i=0; i<citations.size(); i++) {
            if(citations[i] >= mid) {
                mcnt++;
            }
        }
        if(mcnt >= mid) {
            L = mid + 1;
            answer = mid;
        } else {
            R = mid - 1;
        }
    }
    
    return answer;
}