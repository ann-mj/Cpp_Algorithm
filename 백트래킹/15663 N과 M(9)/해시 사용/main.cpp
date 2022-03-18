#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N, M;
int arr[9]; // M개 까지 저장
int vis[9]; // N개 까지 저장
vector<int> nums;
unordered_map<string,int> map;
void q_sort(vector<int> &arr, int start, int end) {
    if(start >= end) return;
    int pivot = start;
    int left = start + 1;
    int right = end;

    while(left <= right) {
        while(left <= end && arr[left] <= arr[pivot]) left++;
        while(right > start && arr[right] >= arr[pivot]) right--;

        if(left >= right) {
            int tmp = arr[pivot];
            arr[pivot] = arr[right];
            arr[right] = tmp;
        } else {
            int tmp = arr[right];
            arr[right] = arr[left];
            arr[left] = tmp;
        }
    }
    q_sort(arr, start, right-1);
    q_sort(arr, right+1, end);
}

void func(string res, int cnt) {
    if(cnt == M) {
        // 이미 출력된 수열이면 패스
        if(map[res]) return;
        map[res] = 1;
        for(int i=0; i<M; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int i=0; i<nums.size(); i++) {
        if(vis[i]) continue; // nums 의 i번째 숫자 선택여부 체크
        arr[cnt] = nums[i];
        vis[i] = true;
        string nxt = res;
        nxt.append(to_string(nums[i]));
        func(nxt, cnt+1);
        vis[i] = false;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) {
        int n = 0;
        cin >> n;
        nums.push_back(n);
    }
    q_sort(nums, 0, nums.size()-1);
    func("", 0);
    return 0;
}