#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    if(N == 1) {
        return 0;
    }
    vector<int> answers;
    int Q = N;
    int small = 2;
    while(Q != 1) {
        if(Q % small == 0) {
            Q = Q/small;
            answers.push_back(small);
        } else {
            small++;
        }
    }
    for(auto i : answers) {
        cout << i << '\n';
    }
    return 0;
}