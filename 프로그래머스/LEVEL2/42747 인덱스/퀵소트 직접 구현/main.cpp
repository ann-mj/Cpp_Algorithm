#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void quick_sort(vector<int> &citations, int start, int end) {
    if(start >= end) return;
    int pivot = start;
    int left = start+1;
    int right = end;
    
    while(left <= right) {
        while(left <= end && citations[left] <= citations[pivot]) left++;
        while(right > start && citations[right] >= citations[pivot]) right--;
        
        if(left > right) {
            int temp = citations[pivot];
            citations[pivot] = citations[right];
            citations[right] = temp;
        } else {
            int temp = citations[left];
            citations[left] = citations[right];
            citations[right] = temp;
        }
    }
    quick_sort(citations, start, right -1);
    quick_sort(citations, right+1, end);
}

int solution(vector<int> citations) {
    int answer = 0;
    
    quick_sort(citations, 0, citations.size()-1);
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