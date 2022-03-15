#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    // sort 는 algorithm 헤더에 있다.
    sort(lottos.begin(),lottos.end());
    set<int> wn(win_nums.begin(),win_nums.end());
    // 넣을 때
    // for(int i = 0; i < 6; ++i)
    //    wn.insert(win_nums[i]);

    int cnt=0;
    int zero_cnt=0;
    for(auto l:lottos){
        // set 에서 있는지를 알 수 있는 함수
        if(wn.find(l)!=wn.end()){
            cnt++;
        }
        if(l==0)
            zero_cnt++;
    }

    vector<int> range{6,6,5,4,3,2,1};

    return {range[cnt+zero_cnt],range[cnt]};
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int> lo = {30, 9, 44, 2, 6, 19};
    vector<int> ww = {31, 10, 45, 1, 6, 19};
    vector<int> res = solution(lo,ww);
    for(int e : res) {
        cout << e << ' ';
    }
    return 0;
}