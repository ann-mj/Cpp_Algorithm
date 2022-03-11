#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int alpha[26] = {};

    // TODO 스트링의 i 번째 원소 접근 방법 
    for(int i=0; i<s.size(); i++) {
        alpha[s[i] - 'a']++;
    }

    for(int e : alpha) {
        cout << e << " ";
    }

    return 0;
}