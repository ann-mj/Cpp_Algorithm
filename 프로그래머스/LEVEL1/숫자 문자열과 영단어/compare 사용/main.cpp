#include <iostream>
#include <string>
#include <vector>

using namespace std;
string s_num[10] = {"zero", "one" , "two", "three", "four" , "five" , "six" , "seven" , "eight" , "nine"};

int solution(string s) {
    int answer = 0;
    string candi;
    for(int i=0; i<s.size(); i++) {
        if(s[i] >= '0' && s[i] <= '9') {
            candi.push_back(s[i]);
        } else {
            for (int j = 0; j < 10; j++)
            {
                // string 찾기, 찾았다면 0 을 return 해준다.
                // A.compare(0,A.length(), B, i, A.length())
                // B의 index i 에서부터 A 와 같은지 체크한다.
                if (!s_num[j].compare(0, s_num[j].length(), s, i, s_num[j].length()))
                {
                    candi.push_back(j+'0');
                    i += s_num[j].length() - 1;
                    break;
                }
            }
            
        }
    }
    answer = stoi(candi);
    return answer;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string a = "2three45sixseven";
    cout << solution(a);
    return 0;
}
