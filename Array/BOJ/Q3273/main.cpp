#include <iostream>
#include <algorithm>
using namespace std;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    int arr[n] = {0,}; // 1부터 100만 사이의 수 , 배열의 크기는 최대 10만

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    sort(arr, arr+n);
    
    int from = 0;
    int to = n -1;
    int end = n-1;
    for(int i=0; i < n; i++) {
        from = i;
        to = end;
        while(from < to) {
            if(arr[from] + arr[to] == k) {
                ret++;
                end = to;
                break;
            }
            to--;
        }
    }
    
    cout << ret;
    return 0;
}

