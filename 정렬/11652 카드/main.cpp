#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<ll> arr;
    for(int i=0; i<N; i++) {
        ll a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    ll mxval = arr[0];
    int mxcnt = 0;
    int cnt = 0;
    ll val = arr[0];
    for(int i=0; i<N; i++) {
        if(val == arr[i]) {
            cnt++;
        } else {
            val = arr[i];
            cnt = 1;
        }
        if(mxcnt < cnt) {
            mxval = val;
            mxcnt = cnt;
        }
    }
    cout << mxval << '\n';
    return 0;
}