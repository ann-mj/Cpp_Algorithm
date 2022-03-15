#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int correct_count = 0;
    int num[46] = {0,};
    for(int wn : win_nums) {
        num[wn] = 1;
    }
    for(int l : lottos) {
        if(l == 0) {
            num[0]++;
            continue;
        }
        if(num[l] == 1) {
            correct_count++;
        }
    }
    answer.push_back(min(6, 7-correct_count-num[0]));
    answer.push_back(min(7-correct_count, 6));
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> lo = {30, 9, 44, 2, 5, 18};
    vector<int> ww = {31, 10, 45, 1, 6, 19};
    vector<int> res = solution(lo,ww);
    for(int e : res) {
        cout << e << ' ';
    }
    return 0;
}
