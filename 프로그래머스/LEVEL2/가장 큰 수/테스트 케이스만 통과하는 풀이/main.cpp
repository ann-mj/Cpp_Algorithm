#include <string>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> tmp;
    for(int a : numbers) {
        tmp.push_back(to_string(a));
    }
    sort(tmp.begin(), tmp.end(), cmp);
    if(tmp.front()[0] == '0') return "0";
    for(auto s : tmp) {
        answer.append(s);
    }
    return answer;
}