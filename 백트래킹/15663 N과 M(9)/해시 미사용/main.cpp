#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<int> nums;
int arr[9]; // 숫자들을 담을 배열
bool vis[9]; // 숫자들을 방문 여부 체크

void q_sort(vector<int> &a, int start, int end) {
    if(start >= end) return;
    int pivot = start;
    int left = start + 1;
    int right = end;

    while(left <= right) {
        while(left <= end && a[left] <= a[pivot]) left++;
        while(right > start && a[right] >= a[pivot]) right--;

        if(left >= right) {
            int tmp = a[pivot];
            a[pivot] = a[right];
            a[right] = tmp;
        } else {
            int tmp = a[left];
            a[left] = a[right];
            a[right] = tmp;
        }
    }
    q_sort(a, start, right-1);
    q_sort(a, right+1, end);
}

void func(int cnt) {
    if(cnt == M) {
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int prev = 0; // nums 는 1~10000 사이
    for(int i=0; i<nums.size(); i++) {
        if(vis[i]) continue;
        if(prev == nums[i]) continue;
        vis[i] = true;
        arr[cnt] = nums[i];
        prev = nums[i];
        func(cnt+1);
        vis[i] = false;
    }
}

int main(void) {
    cin >> N >> M;
    while(N--) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    q_sort(nums, 0, nums.size()-1);
    func(0);
    return 0;
}