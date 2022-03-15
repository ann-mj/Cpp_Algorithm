#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i=0; i<new_id.length(); i++) {
        // 대 -> 소
        if(isupper(new_id[i])) {
            new_id[i] = tolower(new_id[i]);
            continue;
        }
        
        // 소문자, 숫자, 빼기, 밑줄, 마침표 빼고 다 제거
        if(new_id[i] >= 'a' && new_id[i] <= 'z') continue;
        if(isdigit(new_id[i])) continue;
        if(new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.') continue;
        new_id.replace(i, 1, "");
        i--;
    }
    
    for(int i=0; i<new_id.length()-1; i++) {
        if(new_id[i] == '.' && new_id[i+1] == '.') {
            new_id.replace(i,2,".");
            i--;
        }
    }
    
    if(new_id[0] == '.') {
        new_id.replace(0,1,"");
    }
    
    if(new_id[new_id.length()-1] == '.') {
        new_id.replace(new_id.length()-1, 1,"");
    }
    
    if(new_id.length() == 0) {
        new_id.push_back('a');
    }
    
    if(new_id.length() >= 16) {
        new_id = new_id.substr(0, 15);
    }
    if(new_id[0] == '.') {
        new_id.replace(0,1,"");
    }
    
    if(new_id[new_id.length()-1] == '.') {
        new_id.replace(new_id.length()-1, 1,"");
    }
    
    if(new_id.length() <= 2) {
        char last_char = new_id[new_id.length()-1];
        while(new_id.length() != 3) {
            new_id.push_back(last_char);
        }
    }
    cout << new_id;
    answer = new_id;
    return answer;
}

int main(void) {
    return 0;
}