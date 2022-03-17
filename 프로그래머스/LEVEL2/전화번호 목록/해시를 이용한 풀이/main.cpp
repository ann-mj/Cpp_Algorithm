#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string,int> map;
    for(string a : phone_book) {
        map[a] = 1;
    }
    
    for(string a : phone_book) {
        for(int i=0; i<a.length()-1; i++) {
            string sbstr = a.substr(0, i+1); // a.length() 까지 해버리면, 자기 자신과 동일해짐.
            if(map[sbstr] == 1) {
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}