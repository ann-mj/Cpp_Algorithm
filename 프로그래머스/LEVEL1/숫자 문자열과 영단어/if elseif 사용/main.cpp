#include <iostream>
#include <string>
#include <vector>

using namespace std;
string s_num[10] = {"zero", "one" , "two", "three", "four" , "five" , "six" , "seven" , "eight" , "nine"};

int solution(string s) {
    int answer = 0;
    string candi;
    for(int i=0; i<s.length(); i++) {
        if(isdigit(s[i])) {
            candi.push_back(s[i]);
        } else {
            if(s[i] == 'z') {
                candi.push_back('0');
                i += 3;
            } else if(s[i] == 'o') {
                candi.push_back('1');
                i += 2;
            } else if(s[i] == 't') {
                if(s[i + 1] == 'w') {
                    candi.push_back('2');
                    i += 2;
                } else {
                    candi.push_back('3');
                    i += 4;
                }
            } else if(s[i] == 'f') {
                if(s[i+1] == 'o') {
                    candi.push_back('4');
                    i += 3;
                } else {
                    candi.push_back('5');
                    i += 3;
                }
            } else if(s[i] == 's') {
                if(s[i+1] == 'i') {
                    candi.push_back('6');
                    i += 2;
                } else {
                    candi.push_back('7');
                    i += 4;
                }
            } else if(s[i] == 'e') {
                candi.push_back('8');
                i += 4;
            } else if(s[i] == 'n') {
                candi.push_back('9');
                i += 3;
            }
        }
    }
    answer = stoi(candi);
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a = "two123two";
    cout << solution(a);
    return 0;
}