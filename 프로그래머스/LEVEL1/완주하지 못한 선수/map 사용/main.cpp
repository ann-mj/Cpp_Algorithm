#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    for(auto s : completion) {
        m[s] = m[s] + 1;
    }
    
    for(auto p : participant) {
        m[p]--;
        if(m[p] < 0) {
            answer = p;
            break;
        }
    }
    return answer;
}