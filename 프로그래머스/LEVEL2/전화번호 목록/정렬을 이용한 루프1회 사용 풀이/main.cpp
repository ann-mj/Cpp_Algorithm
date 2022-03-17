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
    for(int i=0; i<phone_book.size()-1; i++) {
        if(phone_book[i].compare(0, phone_book[i].length(), phone_book[i+1], 0, phone_book[i].length()) == 0) {
            answer = false;
            break;
        }
    }
    return answer;
}