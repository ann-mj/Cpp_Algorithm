#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string& a, string& b) {
    if(a.length() == b.length()) {
        int a_sum = 0;
        int b_sum = 0;
        for(int i=0; i<a.length(); i++) {
            if(a[i] >= 'A' && a[i] <= 'Z') {
                a_sum += 0;
            } else {
                a_sum += a[i] - '0';
            }
            if(b[i] >= 'A' && b[i] <= 'Z') {
                b_sum += 0;
            } else {
                b_sum += b[i] - '0';
            }
        }
        if(a_sum == b_sum) {
            return a < b;
        } else {
            return a_sum < b_sum;
        }
    } else {
        return a.length() < b.length();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<string> arr;
    for(int i=0; i<N; i++) {
        string a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(string a : arr) {
        cout << a << '\n';
    }
    
    return 0;
}