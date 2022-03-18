#include <string>
#include <vector>

using namespace std;

int cnt;

// cur : 현재까지 가치의 합, level : 현재 탐색할 레벨(1부터 실질적인 탐색함)
void dfs(int cur, int level, vector<int> numbers, int target) {
    if(level == numbers.size()) {
        if(cur == target) cnt++;
        return;
    }
    dfs(cur + numbers[level], level+1, numbers, target);
    dfs(cur -numbers[level], level+1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    // 현재 값, 다음 값, level (numbers.size())
    dfs(0, 0, numbers, target);
    answer = cnt;
    return answer;
}