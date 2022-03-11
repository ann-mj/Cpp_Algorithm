#include <iostream>
using namespace std;

string a,b;
int ret;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;

    // 개수가 다른 알파벳들을 제거한다.
    int num1[26] = {0,};
    int num2[26] = {0,};

    for(int i=0; i<a.length(); i++) {
        num1[a[i] - 'a']++;
    }
    for(int i=0; i<b.length(); i++) {
        num2[b[i] - 'a']++;
    }

    for(int i=0; i<26; i++) {
        if(num1[i] != num2[i]) {
            ret += max(num1[i],num2[i]) - min(num1[i],num2[i]);
        }
    }

    cout << ret;
    return 0;
}