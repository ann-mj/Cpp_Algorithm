#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int> map;
    for(vector<string> c : clothes) {
        map[c[1]]++;
    }
    int sum = 0;
    int mul = 1;
    for(auto m : map) {
        sum += m.second;
        mul *= (m.second + 1);
    }
    // -1 을 해주는 이유 : 모두 안입는 경우를 빼줌
    answer = (mul - 1);
    if(map.size() == 1) {
        mul = 1;
        answer = sum;
    }
    return answer;
}