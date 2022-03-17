#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    // 정렬
    sort(phone_book.begin() , phone_book.end());
    
    // 2중 포문 
    bool ch = true;
    for(int i=0; i<phone_book.size(); i++) {
        for(int j = i+1; j < phone_book.size(); j++) {
            ch = true;
            // 접두어 인지 비교
            string sbt = phone_book[j].substr(0, phone_book[i].length());
            if(sbt.compare(0, sbt.length(), phone_book[i], 0, phone_book[i].length()) == 0) {
                answer = false;
                break;
            } else {
                ch = false;
            }
        }
        if(ch) break;
    }
    
    return answer;
}