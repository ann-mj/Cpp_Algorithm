#include <iostream>
#include <string>
#include <vector>

using namespace std;

void quick_sort(int *arr, int start, int end) {
    if (start >= end) return;
    int pivot = start;
    int left = start + 1;  // pivot 보다 큰 값
    int right = end; // pivot 보다 작은 값
    
    while(left <= right) {
        while(left <= end && arr[left] <= arr[pivot]) {
            left++;
        }
        while(right > start && arr[right] >= arr[pivot]) {
            right--;
        }
        if(left > right) {
            int temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
        } else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    quick_sort(arr, start, right-1);
    quick_sort(arr, right+1, end);
}

int solution(vector<int> citations) {
    int answer = 0;
    int a[5] = {0,};
    for(int i=0; i<citations.size(); i++) {
        a[i] = citations[i];
    }
    
    quick_sort(a, 0, citations.size()-1);
    for(int b : a) {
        cout << b << ' ';
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> aaaa = {3,0,6,1,5};
    int k = solution(aaaa);
    return 0;
}