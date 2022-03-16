#include <string>
#include <vector>
#include <iostream>
using namespace std;

char board[5][4] = {{' ',' ',' ',' '},
                    {' ','1','2','3'},
                    {' ','4','5','6'},
                    {' ','7','8','9'},
                    {' ','*','0','#'}};

int cal_dist(pair<int,int> src, pair<int,int> target) {
    // src : 1,4,7,*  || 3,6,9,#
    // 맨 위 : 1,1 맨 아래 : 4,3
    return abs(src.first - target.first) + abs(src.second - target.second);
}

pair<int,int> get_pos(int num) {
    pair<int,int> res;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=3; j++) {
            if(board[i][j] == (num + '0')) {
                res = make_pair(i,j);
            }
        }
    }
    return res;

}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int,int> left = make_pair(4,1);
    pair<int,int> right = make_pair(4,3);
    
    // 1,4,7 -> L
    // 3,6,9 -> R
    // 2,5,8,0 은 최근 L, R 에서 가까운놈
    for(auto n : numbers) {
        if(n == 1 || n == 4 || n == 7) {
            left = get_pos(n);
            answer.push_back('L');
        } else if(n == 3 || n == 6 || n == 9) {
            right = get_pos(n);
            answer.push_back('R');
        } else {
            pair<int,int> tar = get_pos(n);
            int ld = cal_dist(left,tar);
            int rd = cal_dist(right,tar);
            if(ld == rd) {
                if(hand[0] == 'r') {
                    right = tar;
                    answer.push_back('R');
                } else {
                    left = tar;
                    answer.push_back('L');
                }
            } else {
                if(ld < rd) {
                    left = tar;
                    answer.push_back('L');
                } else {
                    right = tar;
                    answer.push_back('R');
                }
            }
        }
    }
    return answer;
}