#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> m;
    for(auto r : record) {
        string nick = "";
        string ke = "";
        string v = "";
        int last_uid_position = 0;
        if(r[0] == 'E') {
            last_uid_position = r.find(" ", 6);
            for(int i=6; i<last_uid_position; i++) {
                ke.push_back(r[i]);
            }
            nick = r.substr(last_uid_position +1);
            m[ke] = nick;
        } else if(r[0] == 'C') {
            last_uid_position = r.find(" ", 7);
            for(int i=7; i<last_uid_position; i++) {
                ke.push_back(r[i]);
            }
            nick = r.substr(last_uid_position +1);
            m[ke] = nick;
        }
    }
    
    for(string msg : record) {
        string ke = "";
        int pos = 0;
        if(msg[0] == 'E') {
            pos = msg.find(" ", 6);
            for(int i=6; i<pos; i++) {
                ke.push_back(msg[i]);
            }
            answer.push_back(m[ke]+"´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.");
        } else if(msg[0] == 'L') {
            answer.push_back(m[msg.substr(6)]+"´ÔÀÌ ³ª°¬½À´Ï´Ù.");
        }
    }
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<string> rec = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    vector<string> ans = solution(rec);
    for(auto s : ans) {
        
        cout << s << '\n';
    }
    return 0;
}