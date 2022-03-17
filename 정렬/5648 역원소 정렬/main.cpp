#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string& a, string& b) {
    if(a.length() == b.length()) {
        return a < b;
    } else{
        return a.length() < b.length();
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<string> answer;
    vector<string> tmp;
    for(int i=0; i<N; i++) {
        string a;
        cin >> a;
        tmp.push_back(a);
    }

    for(string a : tmp) {
        // 뒤집기
        while(a.back() == '0') {
            a.pop_back();
        }

        string inv = "";
        while(a.length() != 0) {
            inv.push_back(a.back());
            a.pop_back();
        }
        // 넣기
        answer.push_back(inv);
    }

    sort(answer.begin(), answer.end(), cmp);
    for(string an : answer) {
        cout << an << '\n';
    }
    return 0;
}