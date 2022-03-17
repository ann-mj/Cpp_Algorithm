#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
void quick_sort(vector<int> &arr, int start, int end) {
    if(start >= end) return;
    int pivot = start;
    int left = start +1;
    int right = end;
    while(left <= right) {
        while(left <= end && arr[left] <= arr[pivot]) left++;
        while(right > start && arr[right] >= arr[pivot]) right--;
        if(left > right) {
            int temp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = temp;
        } else {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
        }
    }
    quick_sort(arr, start, right-1);
    quick_sort(arr, right+1, end);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> N;
    vector<int> arr;
    for(int i=0; i<N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    quick_sort(arr, 0, arr.size()-1);
    for(int a : arr) {
        cout << a << '\n';
    }
    return 0;
}