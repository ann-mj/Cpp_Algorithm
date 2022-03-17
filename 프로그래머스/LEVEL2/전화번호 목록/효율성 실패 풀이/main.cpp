#include <string>
#include <vector>
#include <algorithm>

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
            // 접두사로 시작하는지 비교
            for(int k=0; k<phone_book[i].size(); k++) {
                if(phone_book[i][k] != phone_book[j][k]) {
                    ch = false;
                    break;
                }
            }
            if(!ch) continue;
            answer = false;
            break;
        }
        if(ch) break;
    }
    
    return answer;
}