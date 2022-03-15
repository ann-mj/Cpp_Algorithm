#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto i : arr) {
        answer += i;
    }
    answer = answer / (arr.size());
    return answer;
}

int main(void) {
    return 0;
}